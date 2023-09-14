#include <boost/fiber/all.hpp>
#include <boost/fiber/fiber.hpp>
#include <chrono>
#include <ctime>
#include <glog/logging.h>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
// fiber quick sort
void quicksort(boost::fibers::buffered_channel<std::vector<int>> &pipe) {
  std::vector<int> data;
  pipe.pop(data);
  if (data.size() > 1) {
    std::vector<int> left, right;
    for (int i = 1; i < data.size(); i++) {
      if (data[i] < data[0])
        left.push_back(data[i]);
      else
        right.push_back(data[i]);
    }
    pipe.push(left);
    pipe.push(right);
  }
}
int main() {
  boost::fibers::buffered_channel<std::vector<int>> pipe(1024);
  std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8};
  boost::fibers::fiber f(quicksort, std::ref(pipe));
  pipe.push(data);
  std::vector<int> sorted;
  pipe.pop(sorted);
  f.join();
  for (auto i : sorted)
    std::cout << i << " ";
  std::cout << "\n";

  return 0;
}