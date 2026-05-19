WRITER.C
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
int main()
{
    key_t key;
    int shmid;
    char *str;
    FILE *fp = fopen("shmfile", "w");
    fclose(fp);
    key = ftok("shmfile", 65);
    shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    str = (char*) shmat(shmid, NULL, 0);
    printf("Enter First Message: ");
    fgets(str, 1024, stdin);
    printf("Memory Now Contains: %s\n", str);
    printf("\nEnter Second Message (Overwrite): ");
    fgets(str, 1024, stdin);
    printf("Memory Now Contains: %s\n", str);
    shmdt(str);
    return 0;
}

READER.C
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>

int main()
{
    key_t key;
    int shmid;
    char *str;

    key = ftok("shmfile", 65);
    if (key == -1) {
        perror("ftok failed");
        return 1;
    }

    shmid = shmget(key, 1024, 0666);
    if (shmid == -1) {
        perror("shmget failed");
        return 1;
    }

    str = (char*) shmat(shmid, NULL, 0);
    if (str == (char*) -1) {
        perror("shmat failed");
        return 1;
    }

    printf("Data read from memory: %s\n", str);

    shmdt(str);

    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
