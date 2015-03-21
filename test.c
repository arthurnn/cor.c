#include <stdio.h>
#include "cor.h"

#define N 1024

typedef struct {
  coroutine* c;
  int ret;
} entry;

void core(void *arg)
{
  entry* it = (entry*) arg;
  it.ret = 10;
  yield(it->c);

  it.ret = 20;
  yield(it->c);

  it.ret = 30;
  yield(it->c);
}

int main(void)
{
  coroutine c;
  int stack[N];
  entry e = {&c};
  start(&c, &core, &e, stack+N);
  while(next(&c)) {
    printf("%d \n", e.ret);
  }
}
