#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

void run_ls()
{
    if (fork() == 0)
    {
        execlp("ls", "ls", NULL);
        perror("ls failed");
    }
    else
        wait(NULL);
}
void run_echo()
{
    char msg[200];
    printf("Enter message: ");
    getchar();
    fgets(msg, sizeof(msg), stdin);
    write(1, msg, strlen(msg));
}
void run_cat()
{
    char file[50], buf[100];
    int fd, n;
    printf("Enter filename: ");
    scanf("%s", file);
    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        perror("cat failed");
        return;
    }
    while ((n = read(fd, buf, sizeof(buf))) > 0)
        write(1, buf, n);
    close(fd);
}

void run_cp()
{
    char src[50], dest[50], buf[100];
    int fd1, fd2, n;
    printf("Enter source file: ");
    scanf("%s", src);
    printf("Enter destination file: ");
    scanf("%s", dest);
    fd1 = open(src, O_RDONLY);
    fd2 = open(dest, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd1 < 0 || fd2 < 0)
    {
        perror("cp failed");
        return;
    }
    while ((n = read(fd1, buf, sizeof(buf))) > 0)
        write(fd2, buf, n);
    close(fd1);
    close(fd2);
    printf("File copied successfully\n");
}

void run_rm()
{
    char file[50];
    printf("Enter file to delete: ");
    scanf("%s", file);

    if (unlink(file) == 0)
        printf("File deleted successfully\n");
    else
        perror("rm failed");
}

int main()
{
    int ch;

    while (1)
    {
        printf("\n--- UNIX Command Menu ---\n");
        printf("1. ls\n");
        printf("2. echo\n");
        printf("3. cat\n");
        printf("4. cp\n");
        printf("5. rm\n");
        printf("6. exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1: run_ls(); break;
        case 2: run_echo(); break;
        case 3: run_cat(); break;
        case 4: run_cp(); break;
        case 5: run_rm(); break;
        case 6: return 0;
        default: printf("Invalid choice\n");
        }
    }
}
