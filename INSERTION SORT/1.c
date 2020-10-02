#include<stdio.h>
int main()
{
    int i,a[]={3,1,5,4,2};
    for(i=0;i<4;i++)
    {
        int j=i+1;
        while(j-- && a[i]>a[i+1])
        {
            int b=a[i];
            a[i]=a[i+1];
            a[i+1]=b;
            i--;
        }

    }
    for(int k=0;k<5;k++)
    {
        printf("%d ",a[k]);
    }
}
