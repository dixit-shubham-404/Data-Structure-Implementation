<<<<<<< HEAD
//rod cutting problem

#include<bits/stdc++.h>
using namespace std;

int rodCutting(int price[],int n,,int size)
{
	int len[n];
	for(int i=0;i<n;i++)
		arr[i]=i+1;
	
	dp[n+1][size+1];  //first is size of array and second is length of rod
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=size;j++)
		{
			if(len[i-1]<=j)
				dp[i][j]=max(price[i-1]+dp[i][j-len[i-1]],dp[i-1][j]);
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][size];
}

int main()
{
	int price[]={1, 5, 8, 9, 10, 17, 17, 20};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<rodCutting(price,n,n);
=======
//rod cutting problem

#include<bits/stdc++.h>
using namespace std;

int rodCutting(int price[],int n)
{
	int len[n];
	for(int i=0;i<n;i++)
		arr[i]=i+1;
	
	dp[n+1][n+1];  //first is size of array and second is length of rod
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(len[i-1]<=j)
				dp[i][j]=max(price[i-1]+dp[i][j-len[i-1]],dp[i-1][j]);
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][n];
}

int main()
{
	int price[]={1, 5, 8, 9, 10, 17, 17, 20};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<rodCutting(price,n);
>>>>>>> 351d620f7104d0725e1d704ac244431e54c58cee
}