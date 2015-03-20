#include <setjmp.h>

typedef struct {
  jmp_buf callee_ctx;
  jmp_buf caller_ctx;
} coroutine;

typedef void (*func)(void*);

void start(coroutine* c, func f, void* arg, void* sp);
int next(coroutine* c);
void yield(coroutine* c);
