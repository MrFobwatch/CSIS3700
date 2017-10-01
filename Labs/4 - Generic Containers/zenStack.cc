#include "zenStack.h"

void ZenStack::push(void *p) throw (ContainerFullException) {

  if (count == STACK_SIZE)
    throw ContainerFullException("ZenStack");

  memcpy(data+count*dSize,p,dSize);

  count++;
}

void ZenStack::pop(void *p) throw (ContainerEmptyException) {

  if (count == 0)
    throw ContainerEmptyException("ZenStack");

  count--;

  memcpy(p,data+count*dSize,dSize);
}

void ZenStack::peek(void *p) throw (ContainerEmptyException) {

  if (count == 0)
    throw ContainerEmptyException("ZenStack");

  memcpy(p,data+(count-1)*dSize,dSize);
}
