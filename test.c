#include <stdio.h>
#include "cor.h"

typedef struct {
  coroutine* c;
  int ret;
} entry;

void core(void *arg)
{
  entry* it = (entry*) arg;
  yield(it->c);
}

int main(void)
{
  coroutine c;
  start(&c, &core, void, stack+N);
  while(next(&c)) {
    printf("%d \n", it.ret);
  }
}
