#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include "header.h" 

void eat(int position)
{
  printf("Filósofo %d comendo...\n", position);
}