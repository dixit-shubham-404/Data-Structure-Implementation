#include<stdio.h>

void Merge(int arr[],int low,int mid,int high)
{
	int temp[high-low+1];
	int i=low,j=mid+1,k=0;
	while(i<=mid&&j<=high)
	{
		if(arr[i]>arr[j])
		{
			temp[k]=arr[j];
			k++;
			j++;
		}
		else
		{
			temp[k]=arr[i];
			k++;
			i++;
		}
	}
	while(i<=mid)
	{
		temp[k]=arr[i];
		k++;i++;
	}
	while(j<=high)
	{
		temp[k]=arr[j];
		k++;j++;
	}
	for(int i=low,k=0;i<=high;i++,k++)
	{
		arr[i]=temp[k];
	}
}

void MergeSort(int arr[],int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		MergeSort(arr,low,mid);
		MergeSort(arr,mid+1,high);
		Merge(arr,low,mid,high);
	}
}

int main()
{
	int arr[]={15,5,10,4,20,11,11,11,0,0,0,0};
	int size=sizeof(arr)/sizeof(arr[0]);
	MergeSort(arr,0,size-1);
	printf("The sorted array is:\n");
	for(int i=0;i<size;i++)
		printf("%d ",arr[i]);
	return 0;
}