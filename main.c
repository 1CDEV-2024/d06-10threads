#include <pthread.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

#define THREADS_MAX 10

typedef struct {
  unsigned n;
} params_t;

void *func(void *__p) {
  params_t *p = (params_t *)__p;

  printf("[THREAD %d] Start.\n", p->n);
  sleep((p->n + 1) * 5);
  printf("[THREAD %d] Stop.\n", p->n);
  return NULL;
}

int main(void) {
  pthread_t threads[THREADS_MAX] = {0};
  params_t params[THREADS_MAX] = {0};

  for (unsigned i = 0; i < THREADS_MAX; i += 1) {
    params[i].n = i;
    pthread_create(&(threads[i]), NULL, func, &(params[i]));
  }

  for (unsigned i = 0; i < THREADS_MAX * 5; i += 1) {
    printf("[MAIN THREAD] Time elapsed: %d seconds.\n", i);
    sleep(1);
  }

  return 0;
}
