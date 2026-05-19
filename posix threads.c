#include <stdio.h>
#include <pthread.h>

// Thread function
void* print_message(void* arg) {
    int thread_num = *(int*)arg;
    printf("Thread %d is running\n", thread_num);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int a = 1, b = 2;

    // Create threads
    pthread_create(&t1, NULL, print_message, &a);
    pthread_create(&t2, NULL, print_message, &b);

    // Wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Both threads finished execution\n");

    return 0;
}