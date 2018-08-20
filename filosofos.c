#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include "header.h"

void *philosopher(void *params)
{
  int i;
  params_t self = *(params_t *)params;

  for(i = 0; i < 100; i++) {
    think(self.position);

    sem_wait(self.lock);
    sem_wait(&self.forks[self.position]);
    sem_wait(&self.forks[(self.position + 1) % self.count]);
    eat(self.position);
    sem_post(&self.forks[self.position]);
    sem_post(&self.forks[(self.position + 1) % self.count]);
    sem_post(self.lock);
  }

  think(self.position);
  pthread_exit(NULL);
}