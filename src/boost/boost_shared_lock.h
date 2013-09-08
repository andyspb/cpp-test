#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>
#include <iostream>

boost::shared_mutex value_mutex;
boost::mutex io_mutex_value; //not used.

template<typename T>
struct multy_max {
    void operator()() {
      std::cout << "enter operator()\n";
      char current_max = 0;
      for (; first != last; ++first) {
        //try to aquire the new current max.
        //use old value if share not aquired
        if (value_mutex.try_lock_shared()) {
          current_max = *output;
          std::cout << " " << current_max;
          value_mutex.unlock_shared();
        }
        T value = *first;
        if (value > current_max) {
          //A new potential max was found.
          //Aquire a shared lock and make sure it really is a max.
          value_mutex.lock_upgrade();
          if (value > *output) {
            //it really is a max, lock and upgrade
            value_mutex.unlock_upgrade_and_lock();
            std::cout << "thread " << id << " has found a new max: " << value
                << std::endl;
            *output = value;
            *outputId = id;
            value_mutex.unlock();
          } else {
            value_mutex.unlock_upgrade();
          }
        }
      }
    }

    const T* first;
    const T* last;
    int id;
    T* output;
    int* outputId;
};

int SharedLockTest(/*int argc, char* argv[]*/) {
  char a[] = "bdhesYifurgshszzjdyeskdos";
  size_t sizeA = sizeof(a) / sizeof(a[0]);

  char output = 0;
  int outputId = 0;

  std::cout << "multi_max definition\n";
  multy_max<char> firstHalf = { a, a + sizeA / 2, 1, &output, &outputId };

  multy_max<char> secondHalf =
      { a + sizeA / 2, a + sizeA, 2, &output, &outputId };

  std::cout << "start threads\n";
  boost::thread thrd1(firstHalf);
  boost::thread thrd2(secondHalf);

  thrd1.join();
  thrd2.join();

  std::cout << "The max is " << output << " and has been found by thread "
      << outputId << ";" << std::endl;
  return 0;
}

