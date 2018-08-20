typedef struct {
  int position;
  int count;
  sem_t *forks;
  sem_t *lock;
} params_t;
void run_all_threads(pthread_t *threads, sem_t *forks, sem_t *lock, int num_philosophers);
void initialize_semaphores(sem_t *lock, sem_t *forks, int num_forks);
void *philosopher(void *params);
void think(int position);
void eat(int position);

