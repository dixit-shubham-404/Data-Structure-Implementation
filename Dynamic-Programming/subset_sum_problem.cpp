/*
	SUBSET SUM PROBLEM
	
	In this problem we are given an array of some numbers we have to predict whether
	the target sum can be achieved by including subset of array or by including
	some elements of array.
	
	Dynamic Programming approach
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int arr={};
	int sum;
	int n=sizeof(arr)/sizeof(arr[0]);
	
	bool dp[n+1][sum+1];
	for(int j=1;j<sum+1;j++)
		dp[0][j]=false;
	
	for(int i=0;i<=n;i++)
		dp[i][0]=true;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(arr[i-1]<=j)
			{
				t[i][j]=t[i-1][j-arr[i-1]]||t[i-1][j];
			}
			else
			{
				t[i][j]=t[i-1][j];
			}
		}
	}
	cout<<dp[n][sum]<<endl;
}