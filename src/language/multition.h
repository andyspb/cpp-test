#pragma once

namespace multition {
class _MyCriticalSection // : public CRITICAL_SECTION
{
  public:
    _MyCriticalSection() {
      //          InitializeCriticalSection(this);
    }
    virtual ~_MyCriticalSection() {
      //          DeleteCriticalSection(this);
    }
};

class FooMultiton {
  private:
    FooMultiton() /* also acceptable: protected, {default} */{
      /* no explicit implementation */
    }

  public:
    static FooMultiton * getInstance(string key) {
      _MyCriticalSection cs;
      printf("Get Object %s\n", key.c_str());
      //      EnterCriticalSection(&cs);
      map<string, FooMultiton *>::iterator iter = instances.find(key);
      FooMultiton * instance;
      if (iter == instances.end()) {

        instance = new FooMultiton();
        instances.insert(pair<string, FooMultiton *>(key, instance));
      } else {
        instance = (FooMultiton *) iter->second;
      }

      //    LeaveCriticalSection(&cs);
      return instance;

    }

    static int getObjectPoolSize() {
      return (int) instances.size();
    }
    // other fields and methods ...
  private:
    static map<string, FooMultiton *> instances;

};

map<string, FooMultiton *> FooMultiton::instances;

int test() {
  printf("Multition pattern example\n");
  printf("number of objects:%d\n", FooMultiton::getObjectPoolSize());
  FooMultiton * fm_1 = FooMultiton::getInstance("test_1");
  FooMultiton * fm_2 = FooMultiton::getInstance("test_2");
  FooMultiton * fm_3 = FooMultiton::getInstance("test_1");
  FooMultiton * fm_4 = FooMultiton::getInstance("test_3");
  printf("number of objects:%d\n", FooMultiton::getObjectPoolSize());
  printf("\n");
  return 0;
}
}
