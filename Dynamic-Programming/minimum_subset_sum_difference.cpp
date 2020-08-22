#include<bits/stdc++.h>
using namespace std;


vector<int> validSum(int arr[], int n,int sum)
{
	bool dp[n+1][sum+1];
	for(int i=0;i<=n;i++)
	{
		dp[i][00]=1;
	}
	for(int j=1;j<=sum;j++)
	{
		dp[0][j]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(arr[i-1]<=j)
			{
				dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	vector<int> var;
	for(int j=0;j<=sum;j++)
	{
		if(dp[n][j])
			var.push_back(j);
	}
	return var;
	
}

int minimumSubsetDifference(int arr[],int n)
{
	
	int min_diff=INT_MAX,range=0;
	for(int i=0;i<n;i++)
	{
		range+=arr[i];
	}
	vector<int> valid=validSum(arr,n,range);
	int it;
	if(valid.size()%2==0)
	{
		it=valid.size()/2;
	}
	else{
		it=(valid.size()/2)+1;
	}
	for(int i=0;i<it;i++)
	{
		min_diff=min(min_diff,range-2*valid[i]);
	}
	return min_diff;
}

int main()
{
	int arr[]={1, 6, 11, 5};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<minimumSubsetDifference(arr,n);
}