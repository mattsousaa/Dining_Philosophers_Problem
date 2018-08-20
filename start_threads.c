#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include "header.h"

void run_all_threads(pthread_t *threads, sem_t *forks, sem_t *lock, int num_philosophers)
{
  int i;
  for(i = 0; i < num_philosophers; i++) {
    params_t *arg = malloc(sizeof(params_t));
    arg->position = i;
    arg->count = num_philosophers;
    arg->lock = lock;
    arg->forks = forks;

    pthread_create(&threads[i], NULL, philosopher, (void *)arg);
  }
}