#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define INT_MAX 10000
struct pro
{
    int at;
    int no;
    int et;
    int ct;
    int bt;
    int pr;
    int btc;
};

int sort(struct pro **arr,int n,int t)
{
    int i,j;
    for(i=0;i<n-1;i++)
	{
            for(j=i+1;j<n;j++)
            {
                    if(arr[i]->pr>arr[j]->pr)
                    {
                        struct pro* t=arr[i];
                        arr[i]=arr[j];
                        arr[j]=t;
                    }
            }
	}

    int	pos=-1,cnt=0;
	for(i=0;i<n;i++)
    {
        if(arr[i]->at<=t)
            {
                cnt++;
                if(arr[i]->bt>0)
                    {
                        pos=i;
                        return pos;
                    }
            }
    }
    if(cnt==n)
        pos=-2;
    return pos;
}

int main()
{
	printf("Enter the total number of processes :");
	int n,i;
	scanf("%d",&n);
	struct pro **arr;
	arr=malloc(n*sizeof(struct pro*));

	for(i=0;i<n;i++)
	{
	    arr[i]=malloc(sizeof(struct pro));
        printf("The burst time for P%d :\n",i+1);
        scanf("%d",&arr[i]->bt);
        printf("The priority for P%d : \n",i+1);
        scanf("%d",&arr[i]->pr);
        printf("The arrival time for P%d : \n",i+1);
        scanf("%d",&arr[i]->at);
        arr[i]->no=i+1;
        arr[i]->ct=0;
        arr[i]->btc=arr[i]->bt;
	}
    printf("Choose any 1 : \n1.Preemptive SJF Scheduling \n2.Round Robin Scheduling\n3.Non-preemptive Priority Scheduling \n");
    int sw;
    scanf("%d",&sw);

    int t=0,c=0,pos;
    int s,si;

    switch(sw)
    {
    case 1:
        while(c<n)
    {
        s=INT_MAX;
        si=-1;

        for(i=0;i<n;i++)
        {
            if(arr[i]->at<=t&&arr[i]->bt>0)
            {
                if(arr[i]->bt<s)
                    {
                        si=i;
                        s=arr[i]->bt;
                    }
            }
        }

        if(si!=-1)
        {
            arr[si]->bt--;
            printf(" P%d ",arr[si]->no);
            t++;
            if(arr[si]->bt==0)
                {
                arr[si]->et=t;
                c++;
                }
        }
        else
           {
               t++;
               printf(" - ");
           }
    }
        break;
    case 2:

        while(c<n)
    {
        int f=0;
        for(i=0;i<n;i++)
        {
            if(arr[i]->at<=t&&arr[i]->bt>0)
            {
                    f=1;
                    arr[i]->bt--;
                    t++;

                    printf(" P%d ",arr[i]->no);
                    if(arr[i]->bt==0)
                        {
                            arr[i]->et=t;
                            c++;
                            continue;
                        }

                    arr[i]->ct++;
                    if(arr[i]->ct==3)
                        {
                            arr[i]->ct=0;
                            i++;
                        }
                    i--;
            }
        }
        if(f!=1)
        {
            t++;
            printf("-");
        }
    }
        break;
    case 3:
        while(1)
        {
            pos = sort(arr,n,t);
            if(pos==-1)
            {
                printf(" - ");
                t++;
                continue;
            }
            else if(pos==-2)
                break;
            else
            {
                t+=arr[pos]->bt;
                for(i=0;i<arr[pos]->bt;i++)
                    printf(" P%d ",arr[pos]->no);
                arr[pos]->bt=0;
                arr[pos]->et=t;
                arr[pos]->pr=INT_MAX;
            }
        }

        break;
    }
        float aw = 0;
        int temp;
        printf("\nWaiting time : \n");
		for(i=0;i<n;i++)
	{
        temp = arr[i]->et-arr[i]->btc-arr[i]->at;
        printf("The waiting time for P%d : ",arr[i]->no);
        printf("%d\n",(temp));
        aw=aw+temp;
	}
	aw/=n*1.0;
	printf("\n The average waiting time : %f",aw);
	return 0;
}
