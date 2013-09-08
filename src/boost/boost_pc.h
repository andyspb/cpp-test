#ifndef _BOOST_PC_H_
#define _BOOST_PC_H_

#include <boost/thread.hpp>
#include <queue>

namespace boost_pc {
using namespace std;

typedef boost::mutex::scoped_lock scoped_lock;
typedef boost::posix_time::milliseconds milliseconds;

const int max_data_size = 29;
const int max_buffer_size = 5;

struct Shared_buffer {
    queue<int> shared_que;
    bool is_finished;
    boost::mutex io_mutex;
    void AddData(int);
    int GetData(void);
    int GetSize();
};

Shared_buffer shared_buffer;
boost::mutex pc_mutex;
boost::condition pc_full;
boost::condition pc_empty;

void Shared_buffer::AddData(int value) {
  scoped_lock lock(io_mutex);
  shared_que.push(value);
}

int Shared_buffer::GetData() {
  scoped_lock lock(io_mutex);
  int i = shared_que.front();
  shared_que.pop();
  return i;
}

int Shared_buffer::GetSize() {
  scoped_lock lock(io_mutex);
  return static_cast<int>(shared_que.size());
}

void producer_routine() {
  for (int i = 0; i < max_data_size; i++) {
    scoped_lock lock(pc_mutex);
    shared_buffer.AddData(i);
    cout << "producing " << i << endl;
    if (i + 1 == max_data_size) {
      cout << "end of producing data\n";
      shared_buffer.is_finished = true;
    }
    if (shared_buffer.GetSize() == max_buffer_size
        || shared_buffer.is_finished) {
      cout << "buffer full\n";
      pc_full.notify_one();
      if (!shared_buffer.is_finished) {
        pc_empty.wait(pc_mutex);
      }
    }
  }
}

void consumer_routine() {
  while (1) {
    scoped_lock lock(pc_mutex);
    if (shared_buffer.GetSize() == 0) {
      cout << "wait on pc_full.wait\n";
      pc_full.wait(pc_mutex);
    }
    while (shared_buffer.GetSize() > 0) {
      int i = shared_buffer.GetData();
      cout << "\t\tconsuming " << i << endl;
    }
    if (shared_buffer.is_finished) {
      break;
    }
    pc_empty.notify_one();
  }
}

int test () {
  std::cout << "Test: boost pc test --->" << std::endl;
  boost::thread producer_thread(producer_routine);
  boost::thread consumer_thread(consumer_routine);
  producer_thread.join();
  consumer_thread.join();
  std::cout << "<--- test passed" << std::endl;
  return 1;
}
} // namespace boost_pc


#endif // _BOOST_PC_H_
