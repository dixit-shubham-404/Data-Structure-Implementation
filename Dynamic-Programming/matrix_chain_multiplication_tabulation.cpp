#include<bits/stdc++.h>
using namespace std;

int MCM(int arr[],int n)
{
	int dp[n][n];
	int i,j,k,L,q;
	
	for(i=1;i<n;i++)
		dp[i][i]=0;
	
	for(L=2;L<n;L++)
	{
		for(int i=0;i<n-L+1;i++)
		{
			j=i+L-1;
			if(j==n)
				continue;
			dp[i][j]=INT_MAX;
			for(int k=i;k<=j-1;k++)
			{
				q=dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
				dp[i][j]=min(q,dp[i][j]);
			}
		}
	}
	
	return dp[1][n-1];
}

int main()
{
	int arr[]={10, 20, 30, 40, 30};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<MCM(arr,n);
}