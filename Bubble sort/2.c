#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    int a[t];
    for(int l=0;l<t;l++)
    {
        scanf("%d",&a[l]);
    }
    for(int i=0;i<t;i++)
    {

        for(int j=0;j<t-i-1;j++)
        {

            if(a[j]>a[j+1])
            {
                int x=a[j];
                a[j]=a[j+1];
                a[j+1]=x;
            }

        }
    }
    for(int k=0;k<t;k++)
    {
        printf("%d ",a[k]);
    }
}
