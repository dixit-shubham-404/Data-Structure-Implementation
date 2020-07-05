#include<stdio.h>

void swap(int *x,int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
}
int Partition(int arr[],int low,int high)
{
	int i=low,j=high,pivot=arr[low];
	while(i<j)
	{
		i++;
		while(arr[i]<pivot)
		{
			i++;
		}
		while(arr[j]>pivot)
		{
			j--;
		}
		if(i<j)
			swap(&arr[i],&arr[j]);
	}
	swap(&arr[j],&arr[low]);
	return j;
}

void QuickSort(int arr[],int low,int high)
{
	if(low<high)
	{
		int pivot=Partition(arr,low,high);
		QuickSort(arr,low,pivot-1);
		QuickSort(arr,pivot+1,high);
	}
}

int main()
{
	int arr[]={10,16,8,12,15,6,3,9,5};
	int size=sizeof(arr)/sizeof(arr[0]);
	QuickSort(arr,0,size-1);
	printf("The sorted array is :\n");
	for(int i=0;i<size;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}