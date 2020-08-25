//Unbounded knapsack

#include<bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int val[],int wt[],int n,int W)
{
	int dp[n+1][W+1];
	for(int i=0;i<=n;i++)
		dp[i][0]=0;
	
	for(int j=1;j<=W;j++)
		dp[0][j]=0;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=W;j++)
		{
			if(wt[i-1]<=j)
				dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	
	return dp[n][W];
}

int main()
{
	int val[]={10, 40, 50, 70};
	int wt[]={1, 3, 4, 5};
	int W=8;
	int n=sizeof(val)/sizeof(val[0]);
	cout<<unboundedKnapsack(val,wt,n,W);
	
}