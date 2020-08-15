//knapsack problem recursion+memoization

#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];
int max(int a, int b) { return (a > b) ? a : b; }

int knapsack(int val[],int wt[],int W,int n)
{
	if(n==0||W==0)
		return 0;
	
	if(dp[W][n]!=-1)
		return dp[W][n];
	
	if(wt[n-1]<=W)
	{
		dp[W][n]=max(val[n-1]+knapsack(val,wt,W-wt[n-1],n-1),knapsack(val,wt,W,n-1));
		return dp[W][n];
	}
	else
	{
		dp[W][n]=knapsack(val,wt,W,n-1);
		return dp[W][n];
	}
	
}


int main()
{
	int val[] = { 60, 100, 120 }; 
    int wt[] = { 10, 20, 30 }; 
    int W = 50; 
    int n = sizeof(val) / sizeof(val[0]);
	memset(dp,-1,sizeof(dp));
    cout << knapsack( val,wt,W, n)<<endl;;
    return 0;
}


