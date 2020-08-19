/*
	Count subset sum with a given sum
	
	In this problem we have to count the total number of subsets with the given set. 
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int arr[]={3, 3, 3, 3};
	int n=sizeof(arr)/sizeof(arr[0]);
	int sum=6;
	int dp[n+1][sum+1];
	for(int j=1;j<=sum;j++)
		dp[0][j]=0;
	
	for(int i=0;i<=n;i++)
		dp[i][0]=1;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(arr[i-1]<=j)
			{
				dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
			}
			else
				dp[i][j]=dp[i-1][j];
		}
			
	}
	
	cout<<dp[n][sum]<<endl;
}