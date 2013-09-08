namespace mutex_wrapper {
class Mutex {
    pthread_mutex_t mutex;
  public:
    Mutex() {
      pthread_mutex_init(&mutex, 0);
    }
    ~Mutex() {
      pthread_mutex_destroy(&mutex);
    }
  private:
    friend class Lock;
    void lock() {
      pthread_mutex_lock(&mutex);
    }
    void unlock() {
      pthread_mutex_unlock(&mutex);
    }
};

class Lock {
    Mutex& mutex;
  public:
    Lock(Mutex& mutex)
        : mutex(mutex) {
      mutex.lock();
    }
    ~Lock() {
      mutex.unlock();
    }
};
}
