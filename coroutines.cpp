#include <boost/coroutine2/all.hpp>
#include <boost/coroutine2/coroutine.hpp>
#include <functional>
#include <glog/logging.h>
#include <iostream>
void foo(boost::coroutines2::coroutine<int>::pull_type &sink) {
  LOG(INFO) << "foo: entered";
  LOG(INFO) << sink.get();
  LOG(INFO) << "foo: exiting";
}
int main() {
  boost::coroutines2::coroutine<int>::push_type source(foo);
  source(42);
  return 0;
}