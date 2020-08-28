/*Target Sum
	In this problem we have to assign either + or - sign before array elements so that their
	sum is equal to the given sum.
	Print the number of ways its possible.
*/
#include<bits/stdc++.h>
using namespace std;

int targetSum(int arr[],int n,int target_sum)
{
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=arr[i];
	sum=(sum+target_sum)/2;
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
				dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][sum];
}

int main()
{
	int arr[]={1, 1, 1, 1, 1};
	int target_sum=3;
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<targetSum(arr,n,target_sum);
	
}
