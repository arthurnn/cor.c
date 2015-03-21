#include "cor.h"

void start(coroutine* c, func f, void* arg, void* sp)
{
  // allocate stack and run f(arg) there.
}

int next(coroutine* c)
{
  int ret = setjmp(c->caller_ctx);
  if(!ret) {
    longjmp(c->callee_ctx, 1);
  }
  else {
    return ret == 1;
  }
}

void yield(coroutine* c)
{
  if(!setjmp(c->callee_ctx)) {
    longjmp(c->caller_ctx, 1);
  }
}
