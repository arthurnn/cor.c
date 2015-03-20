#include "cor.h"

void start(coroutine* c, func f, void* arg, void* sp)
{
  // allocate stack and run f(arg) there.
}

void next(coroutine* c)
{
  // jumtp to callee context
}

void yield(coroutine* c)
{
  // jump to caller context
}
