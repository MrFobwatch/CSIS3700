#include "die.h"

Die::Die(int _nFaces){
  nFaces = _nFaces;
  top = 0;
}

int Die::roll(void){
  top = 1 + rand() % nFaces;
  return top;
}

int Die::lookAt(void){
  return top;
}
