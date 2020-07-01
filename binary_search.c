#include<stdio.h>
//function to search key element using binary search iterative manner
int binary_search_iterative(int arr[],int l,int h, int key)
{
	int mid=(l+h-1)/2;
	while(l<h)
	{
		if(arr[mid]==key)
			return mid;
		else if(arr[mid]<key)
			l=mid+1;
		else
			h=mid-1;
			
		mid=(l+h-1)/2;	
		
	}
	return -1;
}

//function to search key element using binary search recursive manner
int binary_search_recursive(int arr[],int l,int h,int key)
{
	int mid=(l+h-1)/2;
	if(arr[mid]==key)
		return mid;
	else if(arr[mid]<key)
		return binary_search_recursive(arr,mid+1,h,key);
	else
		return binary_search_recursive(arr,l,mid-1,key);
	
	return -1;
}

int main()
{
	int arr[]={1,10,23,27,40,55,70,80,99};
	int size=sizeof(arr)/sizeof(arr[0]);
	int key=70;
	int result=binary_search_iterative(arr,0,size,key);
	if(result!=-1)
		printf("Using iterative binary search the key element is found at index %d\n",result);
	else 
		printf("Element not found!!\n");
	
	result=binary_search_recursive(arr,0,size,key);
	if(result!=-1)
		printf("Using recursive binary search the key element is found at index %d\n",result);
	else
		printf("Element not found!!\n");
	return 0;
}