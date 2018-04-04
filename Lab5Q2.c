#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{   
    int status;
    int i,j;
    char str[20][20];
    char temp[20];
    printf("\nNumber Of Arguments Passed: %d",argc);
    printf("\n----Following Are The Command Line Arguments Passed----");
    for(i=1;i<argc;i++)
    {
        printf("\n argv[%d]: %s \n ",i,argv[i]);
        strcpy(str[i],argv[i]);
        printf(" \n arr[%d]= %s \n",i,str[i]);

    }

    pid_t a=fork();
    if(a==0)
    {
        for (i = 1; i < argc-1; i++)
        {
            for (j = i+1; j < argc; j++)
                {
                     if (strcmp(str[i], str[j]) > 0)
                       {
                        strcpy(temp, str[i]);
                        strcpy(str[i], str[j]);
                        strcpy(str[j], temp);
                          }
                }
        }

          printf("Using selection sort :\n ");
          for(i=1;i<argc;i++)
          {
            printf("%s \n",str[i]);
          }
    }
    else
    {
        wait(&status);
        printf("\nParent Process:\n");
        for(i=1;i<argc;i++)
            {
                printf("\n argv[%d]: %s \n ",i,argv[i]);
            }   
    }
    return 0;
}

