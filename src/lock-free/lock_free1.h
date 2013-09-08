// lock_free1.h
// author: andrey.krutogolov@gmail.com
// date:   27.03.2013

#ifndef LOCK_FREE1_H_
#define LOCK_FREE1_H_

namespace lock_free1 {

template<class T>
class TLockFreeQueue {
  struct TListNode {
    TListNode * volatile Next;
    T Data;
  };

  struct TRootNode {
    TListNode * volatile PushQueue;
    TListNode * volatile PopQueue;
    TListNode * volatile ToDelete;
    TRootNode * volatile NextFree;

    TRootNode()
        : PushQueue(0),
          PopQueue(0),
          ToDelete(0),
          NextFree(0) {
    }
  };

  static void EraseList(TListNode *n) {
    while (n) {
      TListNode *keepNext = n->Next;
      delete n;
      n = keepNext;
    }
  }

  TRootNode * volatile JobQueue;
  volatile long FreememCounter;
  TRootNode * volatile FreePtr;

  void TryToFreeAsyncMemory() {
    TRootNode *current = FreePtr;
    if (current == 0)
      return;
    if (atomic_add(FreememCounter, 0) == 1) {
      // we are the last thread, try to cleanup
      if (cas(&FreePtr, (TRootNode*) 0, current)) {
        // free list
        while (current) {
          TRootNode *p = current->NextFree;
          EraseList(current->ToDelete);
          delete current;
          current = p;
        }
      }
    }
  }
  void AsyncRef() {
    atomic_add(FreememCounter, 1);
  }
  void AsyncUnref() {
    TryToFreeAsyncMemory();
    atomic_add(FreememCounter, -1);
  }
  void AsyncDel(TRootNode *toDelete, TListNode *lst) {
    toDelete->ToDelete = lst;
    for (;;) {
      toDelete->NextFree = FreePtr;
      if (cas(&FreePtr, toDelete, toDelete->NextFree))
        break;
    }
  }
  void AsyncUnref(TRootNode *toDelete, TListNode *lst) {
    TryToFreeAsyncMemory();
    if (atomic_add(FreememCounter, -1) == 0) {
      // no other operations in progress, can safely reclaim memory
      EraseList(lst);
      delete toDelete;
    } else {
      // Dequeue()s in progress, put node to free list
      AsyncDel(toDelete, lst);
    }
  }

  struct TListInvertor {
    TListNode *Copy;
    TListNode *Tail;
    TListNode *PrevFirst;

    TListInvertor()
        : Copy(0),
          Tail(0),
          PrevFirst(0) {
    }
    ~TListInvertor() {
      if (Copy)
        Copy = Copy;
      EraseList(Copy);
    }
    void CopyWasUsed() {
      Copy = 0;
      Tail = 0;
      PrevFirst = 0;
    }
    void DoCopy(TListNode *ptr) {
      TListNode *newFirst = ptr;
      TListNode *newCopy = 0;
      TListNode *newTail = 0;
      while (ptr) {
        if (ptr == PrevFirst) {
          // short cut, we have copied this part already
          Tail->Next = newCopy;
          newCopy = Copy;
          Copy = 0;  // do not destroy prev try
          if (!newTail)
            newTail = Tail;  // tried to invert same list
          break;
        }
        TListNode *newElem = new TListNode;
        newElem->Data = ptr->Data;
        newElem->Next = newCopy;
        newCopy = newElem;
        ptr = ptr->Next;
        if (!newTail)
          newTail = newElem;
      }
      EraseList(Copy);  // copy was useless
      Copy = newCopy;
      PrevFirst = newFirst;
      Tail = newTail;
    }
  };

  TLockFreeQueue(const TLockFreeQueue&) {
  }
  void operator=(const TLockFreeQueue&) {
  }
 public:
  TLockFreeQueue()
      : JobQueue(new TRootNode),
        FreememCounter(0),
        FreePtr(0) {
  }
  ~TLockFreeQueue() {
    AsyncRef();
    AsyncUnref();
    EraseList(JobQueue->PushQueue);
    EraseList(JobQueue->PopQueue);
    delete JobQueue;
  }
  void Enqueue(const T &data) {
    TListNode *newNode = new TListNode;
    newNode->Data = data;
    TRootNode *newRoot = new TRootNode;
    AsyncRef();
    newRoot->PushQueue = newNode;
    for (;;) {
      TRootNode *curRoot = JobQueue;
      newRoot->PushQueue = newNode;
      newNode->Next = curRoot->PushQueue;
      newRoot->PopQueue = curRoot->PopQueue;
      if (cas(&JobQueue, newRoot, curRoot)) {
        AsyncUnref(curRoot, 0);
        break;
      }
    }
  }
  bool Dequeue(T *data) {
    TRootNode *newRoot = 0;
    TListInvertor listInvertor;
    AsyncRef();
    for (;;) {
      TRootNode *curRoot = JobQueue;
      TListNode *tail = curRoot->PopQueue;
      if (tail) {
        // has elems to pop
        if (!newRoot)
          newRoot = new TRootNode;

        newRoot->PushQueue = curRoot->PushQueue;
        newRoot->PopQueue = tail->Next;
        ASSERT(curRoot->PopQueue == tail);
        if (cas(&JobQueue, newRoot, curRoot)) {
          *data = tail->Data;
          tail->Next = 0;
          AsyncUnref(curRoot, tail);
          return true;
        }
        continue;
      }
      if (curRoot->PushQueue == 0) {
        delete newRoot;
        AsyncUnref();
        return false;  // no elems to pop
      }

      if (!newRoot)
        newRoot = new TRootNode;
      newRoot->PushQueue = 0;
      listInvertor.DoCopy(curRoot->PushQueue);
      newRoot->PopQueue = listInvertor.Copy;
      ASSERT(curRoot->PopQueue == 0);
      if (cas(&JobQueue, newRoot, curRoot)) {
        newRoot = 0;
        listInvertor.CopyWasUsed();
        AsyncDel(curRoot, curRoot->PushQueue);
      } else {
        newRoot->PopQueue = 0;
      }
    }
  }
  bool IsEmpty() {
    AsyncRef();
    TRootNode *curRoot = JobQueue;
    bool res = curRoot->PushQueue == 0 && curRoot->PopQueue == 0;
    AsyncUnref();
    return res;
  }
};

int main() {

  return 0;
}

}  // namespace lock_free1

#endif  // LOCK_FREE1_H_
