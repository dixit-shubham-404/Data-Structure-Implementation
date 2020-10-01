#include<bits/stdc++.h>
using namespace std;

int MCMRecursive(int arr[],int i,int j)
{
	if(i>=j)
		return 0;
	
	int ans=INT_MAX,count;
	for(int k=i;k<=j-1;k++)
	{
		count=MCMRecursive(arr,i,k)+MCMRecursive(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
		ans=min(ans,count);
	}
	return ans;
}


int main()
{
	int arr[]={10, 20, 30, 40, 30};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	cout<<MCMRecursive(arr,1,n-1);
}