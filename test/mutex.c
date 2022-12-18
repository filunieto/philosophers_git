#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
# include<time.h>

int mails = 0;
pthread_mutex_t mutex;

void* routine() {
	void *ptr = NULL;
    for (int i = 0; i < 10000000; i++) {
       //pthread_mutex_lock(&mutex);
        mails++;
       //pthread_mutex_unlock(&mutex);
        // read mails
        // increment
        // write mails
    }
	return (ptr);
}

int main() {
    pthread_t p1, p2, p3, p4;
	clock_t start, end;
	double execution_time;
	start = clock();
    pthread_mutex_init(&mutex, NULL);
    if (pthread_create(&p1, NULL, &routine, NULL) != 0) {
        return 1;
    }
    if (pthread_create(&p2, NULL, &routine, NULL) != 0) {
        return 2;
    }
    if (pthread_create(&p3, NULL, &routine, NULL) != 0) {
        return 3;
    }
    if (pthread_create(&p4, NULL, &routine, NULL) != 0) {
        return 4;
    }
    if (pthread_join(p1, NULL) != 0) {
        return 5;
    }
    if (pthread_join(p2, NULL) != 0) {
        return 6;
    }
    if (pthread_join(p3, NULL) != 0) {
        return 7;
    }
    if (pthread_join(p4, NULL) != 0) {
        return 8;
    }
    pthread_mutex_destroy(&mutex);
	end = clock();
	execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("Number of mails: %d and time of execution %f\n", mails, execution_time);
    return 0;
}