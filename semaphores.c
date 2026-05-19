#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t s;

void* task(void *arg)
{
    int num = *(int*)arg;
    printf("Process %d waiting for resource\n", num);
    sem_wait(&s);   // Enter critical section
   printf("Process %d entered critical section\n", num);
    sleep(2);
    printf("Process %d leaving critical section\n", num);
    sem_post(&s);   // Exit critical section
    return NULL;
}
int main()
{
    pthread_t t1, t2;
    int a = 1, b = 2;
    sem_init(&s, 0, 1);
    pthread_create(&t1, NULL, task, &a);
    pthread_create(&t2, NULL, task, &b);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    sem_destroy(&s);
    return 0;
}
