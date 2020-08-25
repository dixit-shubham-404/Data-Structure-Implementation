//coing change problem maximum number of ways

#include<bits/stdc++.h>
using namespace std;

int coinChange(int arr[],int n,int sum)
{
	int dp[n+1][sum+1];
	for(int i=0;i<=n;i++)
		dp[i][0]=1;
	
	for(int j=1;j<=sum;j++)
		dp[0][j]=0;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(arr[i-1]<=j)
				dp[i][j]=dp[i][j-arr[i-1]]+dp[i-1][j];
			else
				dp[i][j]=dp[i-1][j-1];
		}
	}
	
	return dp[n][sum];
}

int main()
{
	int arr[]={1, 2, 3};
	int sum=4;
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<coinChange(arr,n,sum);
}