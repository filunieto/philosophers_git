#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int x = 1;
int mails = 0;

void* routine3() 
{
	void *ptr = NULL;

    for (int i = 0; i < 100000; i++) {
        mails++;
        // read mails
        // increment
        // write mails
    }
	return (ptr);
}


void	*routine(int *var)
{
    int i;
	for (i = 0; i < 100000; i++)
        x++;
    for (i = 0; i < 10000; i++)
         (*var = i);
	void *ptr = NULL;
	printf("Hello from threads1\n");
	printf("value of x in routine1: |%i|\n", x);
	//printf("Process ID in routine1: |%i|\n", getpid());
	sleep(3);
	printf("END from threads1\n");
	return (ptr);
}


void	*routine2(int *var)
{
    int i;
	for (i = 0; i < 100000; i++)
        x++;
    for (i = 0; i < 10000; i++)
         (*var = *var + 1);
	void *ptr = NULL;
	printf("Hello from threads2\n");
	printf("value of x in routine2: |%i|\n", x);
	//printf("Process ID in routine2: |%i|\n", getpid());
	sleep(3);
	printf("END from threads2\n");
	return (ptr);
}


int	main(void)
{
	int var;
	pthread_t	t1;
	pthread_t	t2;
	pthread_t	t3;

	//var = malloc(sizeof(int));
	var = 0;
	if (pthread_create(&t1, NULL, routine(&var), NULL))
		return 1;
	if (pthread_create(&t2, NULL, routine2(&var), NULL))
		return 2;
	if (pthread_create(&t3, NULL, &routine3, NULL))
		return 1;
	if (pthread_create(&t3, NULL, &routine3, NULL))
		return 1;
	if (pthread_join(t1, NULL))
		return 3;
	if (pthread_join(t2, NULL))
		return 4;
	if (pthread_join(t3, NULL))
		return 3;
	printf("value of x en main: |%i|\n", x);
	printf("value of var en main: |%i|\n", var);
	printf("value of mails en main: |%i|\n", mails);
	//pthread_join(t2, NULL);
	return (0);
}
