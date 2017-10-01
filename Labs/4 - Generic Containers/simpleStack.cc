#include "simpleStack.h"

void Stack::push(const StackType &d) throw (ContainerFullException) {

  if (count == STACK_SIZE)
    throw ContainerFullException("SimpleStack");

  data[count] = d;

  count++;

// data[count++] = d;
}

StackType Stack::pop(void) throw (ContainerEmptyException) {

  if (!count)
    throw ContainerEmptyException("SimpleStack");

  count--;

  return data[count];

// return data[--count];
}

StackType Stack::peek(void) throw (ContainerEmptyException) {

  if (!count)
    throw ContainerEmptyException("SimpleStack");

  return data[count-1];
}
