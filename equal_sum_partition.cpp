/*
	EQUAL SUM PARTITION PROBLEM
	
	In this problem we have to find out whether an array
	can be divided into two subset of equal sum.
*/

#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int arr[],int n,int sum)
{
	bool dp[n+1][sum+1];
	for(int j=1;j<=sum;j++)
		dp[0][j]=false;
	
	for(int i=0;i<=n;i++)
		dp[i][0]=true;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(arr[i-1]<=j)
			{
				dp[i][j]=dp[i-1][j-arr[i-1]]	||	dp[i-1][j];
			}
			else
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	return dp[n][sum];
}

bool equalSumPartition(int arr[],int n)
{
	long long int sum=0;
	for(int i=0;i<n;i++)
		sum+=arr[i];
	
	if(sum%2==0)
	{
		return subsetSum(arr,n,sum/2);
	}
	return false;
}

int main()
{
	int arr[]={1,5,11,5};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<equalSumPartition(arr,n)<<endl;
	return 0;
}