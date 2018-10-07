```
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main() {
    if(fork()==0)
    {
    printf("Child Process is running. \n");
    printf("getpid : %d getppid : %d \n",getpid(),getppid());
    }
    else
    {
    printf("Parent Process is running. \n");
    printf("getpid : %d getppid : %d \n",getpid(),getppid());
    }
    return 0;
}

```
//END OF CODE
