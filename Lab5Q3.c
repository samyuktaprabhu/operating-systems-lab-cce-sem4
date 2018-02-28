#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_LEN 20
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
int returnStatus;
if (pida == 0)
{
/* Child A code */
for (i = 0; i < n - 1 ; i++)
{
    for (j = 0; j < n-i-1; j++)
        {
            if (strcmp(str[j], str[j+1]) > 0)
            {
                strcpy(temp, str[j]);
                strcpy(str[j], str[j+1]);
                strcpy(str[j+1], temp);
            }
        }
}

printf("Using bubble sort : ");
for(i=0;i<n;i++)
{
    printf("Value is %s \n",str[i]);
}

}

else
{
/* Parent Code */
pidb=fork();
if(pidb==0)
{
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
    wait(&returnStatus);
    printf("Parent");
    exit(0);
 }


}
return 0;
}
