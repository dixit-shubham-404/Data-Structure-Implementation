#include<bits/stdc++.h>
using namespace std;

int countTargetDiffSubset(int arr[],int n,int diff)
{
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=arr[i];
	int s1=(sum+diff)/2;
	int dp[n+1][s1+1];
	for(int i=0;i<=n;i++)
		dp[i][0]=1;
	
	for(int j=1;j<=sum;j++)
		dp[0][j]=0;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(arr[i-1]<=j)
			{
				dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
			}
			else
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	return dp[n][sum];
}


int main()
{
	int arr[]={1,1,2,3};
	int n=sizeof(arr)/sizeof(arr[0]);
	int target_diff=1;
	cout<<countTargetDiffSubset(arr,n,target_diff);
}