#include<stdio.h>
int main()
{
	int a[20],b[20],d,n,i,j,temp,s,k=0,c=0,t=0;
	printf("Enter head pointer position: ");
	scanf("%d",&a[0]);
	printf("\nEnter number of processes: ");
	scanf("%d",&n);
	printf("\nEnter processes in request order: ");
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
    b[k++]=a[0];
    for(i=0;i<n;i++)
    {
        s=999;
        for(j=i+1;j<=n;j++)
        {
            if(a[i]>a[j])
                d=a[i]-a[j];
            else
                d=a[j]-a[i];
            if(d<s)
            {
                s=d;
                c=j;
            }
        }
        t+=s;
        temp=a[i+1];
        a[i+1]=a[c];
        a[c]=temp;
        b[k++]=a[i+1];
    }
    printf("\n Final order: \n");
	for(i=0;i<=n;i++)
		printf("%d => ",b[i]);
printf("end \n The total Head Movement: %d",t);
}
