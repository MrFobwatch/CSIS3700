#ifndef _ZENSTACK_H
#define _ZENSTACK_H

#include <cstring>
#include <cstdint>
#include <exceptions.h>

using namespace std;

const int STACK_SIZE = 1024;

class ZenStack {
 public:
  ZenStack(int s) { count = 0; dSize = s; }
  ~ZenStack(void) { }

  void clear(void) { count = 0; }
  int size(void) { return count; }
  bool isEmpty(void) { return count == 0; }

  void push(void *) throw (ContainerFullException);
  void pop(void *) throw (ContainerEmptyException);
  void peek(void *) throw (ContainerEmptyException);

 private:
  uint8_t
    data[STACK_SIZE];
  uint32_t
    count,
    dSize;
};

#endif
