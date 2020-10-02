#include <stdio.h>
#include <stdlib.h>
int count=0;
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}
int binary_search(int a[],int low,int high,int key)
{

    while(low<=high)
    {
       int mid=(low+high)/2;
        if(a[mid]==key)
        {
            count++;
            if(a[mid+1]>=key)
            {
                low=mid+1;
                 if(a[high]==key && a[low])
                {
                    count++;
                }

            }
            else if(a[mid+1]<=key)
            {
                high=mid-1;
                if(a[high]==key && a[low])
                {
                    count++;
                }
            }
        }
        else{
            if(key>a[mid])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }

    }
    return count;
}
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {

		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);

		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);

	}
}

void printArray(int A[], int size)
{
	int i;
	for (i = size; i >=0; i--)
		printf("%d ", A[i]);
	printf("\n");
}

int main()
{
	int arr[10],a[10],t1,i,t,j,h,l,val;
	printf("Size of array 1\n");
	scanf("%d",&t1);
	printf("Enter data\n");
    for(i=0;i<t1;i++)
    {
        scanf("%d",&arr[i]);
    }
	mergeSort(arr, 0, t1 - 1);
	 for(i=t1-1,j=0;i>=0;i--)
    {
        a[j++]=arr[i];
    }
    printf("Size of array 2\n");
	scanf("%d",&t);
	printf("Enter data\n");
    for(i=0;i<t;i++)
    {
        scanf("%d",&arr[i]);
    }
    mergeSort(arr, 0, t - 1);
    for(i=t-1;i>=0;i--)
    {
        a[j++]=arr[i];
    }
    t=t1+t;
    l=0;
    h=t-1;
    mergeSort(a, 0, t-1);
    printf("Enter data to search\n");
    scanf("%d",&val);
    int result=binary_search(a,l,h,val);
    printf("The Sorted Array is\n\n");
    for(i=t-1;i>=0;i--)
    {
        printf("%d ",a[i]);
    }
    printf("\n\n");
    printf("%d is found %d times in the array\n",val,result);

	return 0;
}


