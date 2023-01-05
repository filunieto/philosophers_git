#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ERR_NUM_PHILOSOPHERS 5
#define NUM_FORKS 5

// This solution uses mutexes (mutual exclusion locks) to synchronize
// access to the forks. Each philosopher tries to acquire the mutex
//  for their left fork, and then the mutex for their right fork. 
// If both mutexes are successfully acquired, the philosopher can eat.
// When they are done eating, they release both mutexes and start 
// thinking again.

// This solution ensures that no two philosophers can eat at the
//  same time, preventing deadlock. It also ensures that each philosopher
//   eventually gets a chance to eat, preventing starvation.

pthread_mutex_t forks[NUM_FORKS];

void *philosopher(void *arg) {
  long philosopher_id = (long)arg;

  while (1) {
    // Think for a while
    sleep(1);

    // Pick up the left fork
    pthread_mutex_lock(&forks[philosopher_id]);
    printf("Philosopher %ld picked up left fork\n", philosopher_id);

    // Pick up the right fork
    pthread_mutex_lock(&forks[(philosopher_id + 1) % NUM_FORKS]);
    printf("Philosopher %ld picked up right fork\n", philosopher_id);

    // Eat for a while
    sleep(1);

    // Put down the right fork
    pthread_mutex_unlock(&forks[(philosopher_id + 1) % NUM_FORKS]);
    printf("Philosopher %ld put down right fork\n", philosopher_id);

    // Put down the left fork
    pthread_mutex_unlock(&forks[philosopher_id]);
    printf("Philosopher %ld put down left fork\n", philosopher_id);
  }

  return NULL;
}

int main() {
  pthread_t philosophers[ERR_NUM_PHILOSOPHERS];

  // Initialize the forks
  for (long i = 0; i < NUM_FORKS; i++) {
    pthread_mutex_init(&forks[i], NULL);
  }

  // Create the philosopher threads
  for (long i = 0; i < ERR_NUM_PHILOSOPHERS; i++) {
    pthread_create(&philosophers[i], NULL, philosopher, (void *)i);
  }

  // Wait for the philosopher threads to finish
  for (long i = 0; i < ERR_NUM_PHILOSOPHERS; i++) {
    pthread_join(philosophers[i], NULL);
  }

  return 0;
}
