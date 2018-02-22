```
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_LEN 20
typedef int bool;
#define true 1
#define false 0
int main(){
char str[20][20];
int n;
printf("Enter n:");
scanf("%d",&n);
int i,j;
for(i=0;i<n;i++)
{
scanf("%s",str[i]);
}
for(i=0;i<n;i++)
{
printf("Value initially is %s \n",str[i]);
}
pid_t pida;
pid_t pidb;
char temp[20];
pida=fork();
pidb=fork();
int corun=1;
int ctrun=1;
bool s1=false;
bool s2=false;
   int returnStatus;
    s1 = waitpid(pida, &returnStatus, 0);
    s2 = waitpid(pidb, &returnStatus, 0);
 //  s1 = wait(pid, &returnStatus, 0);
  // s2 = wait(pidb, &returnStatus, 0);
if (pida == 0)
{
    /* Child A code */
     for (i = 0; i < n - 1 ; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (strcmp(str[i], str[j]) > 0)
                {
                    strcpy(temp, str[i]);
                    strcpy(str[i], str[j]);
                    strcpy(str[j], temp);
}}}
printf("Using bubble sort : ");
       for(i=0;i<n;i++)
{
printf("Value is %s \n",str[i]);
}
}
else if(pidb==0)
{
        /* Child B code */
              int i, j, min_idx;

    char minStr[MAX_LEN];
    for (i = 0; i < n-1; i++)
    {

        int min_idx = i;
        strcpy(minStr, str[i]);
        for (j = i+1; j < n; j++)
        {
            if (strcmp(minStr, str[j]) > 0)
            {
                strcpy(minStr, str[j]);
                min_idx = j;
            }
        }

        if (min_idx != i)
        {
            char temp[MAX_LEN];
            strcpy(temp, str[i]);
            strcpy(str[i], str[min_idx]);
            strcpy(str[min_idx], temp);
        }
    }
    printf("Using selection sort : ");
       for(i=0;i<n;i++)
{
printf("Value is %s \n",str[i]);
}
}
else
{
        /* Parent Code */
if(s1)
    {
    printf("Child 1 process finished");
    exit(0);
    }
else if(s2)
    {

    printf("Child 2 process finished");
    exit(0);
    }
    else
    {
    printf("child process not yet done");
    }
}
return 0;
}
```
