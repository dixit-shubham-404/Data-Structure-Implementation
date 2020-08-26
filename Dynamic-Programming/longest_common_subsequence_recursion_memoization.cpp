//longest_common subsequence recursive memoization

#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int LCS(string s1,string s2,int n1,int n2)
{
	if(n1==0||n2==0)
		return 0;
	if(dp[n1][n2]!=-1)
		return dp[n1][n2];
	
	if(s1[n1]==s2[n2])
		dp[n1][n2]=1+LCS(s1,s2,n1-1,n2-1);
	else
		dp[n1][n2]=max(LCS(s1,s2,n1-1,n2),LCS(s1,s2,n1,n2-1));
	
	return dp[n1][n2];
	
}

int main()
{
	memset(dp,-1,sizeof(dp));
	string s1="AGGTAB";
	string s2="GXTXAYB";
	cout<<LCS(s1,s2,s1.size(),s2.size());
	
}