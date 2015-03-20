#include "cor.h"

void start(coroutine* c, func f, void* arg, void* sp)
{
  // allocate stack and run f(arg) there.
}

int next(coroutine* c)
{
  // jumtp to callee context
  return 0;
}

void yield(coroutine* c)
{
  // jump to caller context
}
