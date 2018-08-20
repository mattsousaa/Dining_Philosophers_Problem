#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int main(int argc, char *args[])
{
  int num_philosophers = 5;

  sem_t lock;
  sem_t forks[num_philosophers];
  pthread_t philosophers[num_philosophers];

  initialize_semaphores(&lock, forks, num_philosophers);
  run_all_threads(philosophers, forks, &lock, num_philosophers);
  pthread_exit(NULL);
}