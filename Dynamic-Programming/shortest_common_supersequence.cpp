//shortest common supersequence-gives length

#include<bits/stdc++.h>
using namespace std;

int shortestSupersequence(string s1,string s2,int n1,int n2)
{
	int dp[n1+1][n2+1];
	
	for(int i=0;i<=n1;i++)
		dp[i][0]=0;
	
	for(int j=0;j<=n2;j++)
		dp[0][j]=0;
	
	for(int i=1;i<=n1;i++)
	{
		for(int j=1;j<=n2;j++)
		{
			if(s1[i-1]==s2[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	
	return n1+n2-dp[n1][n2];
}

int main()
{
	string s1="AGGTAB";
	string s2="GXTXAYB";
	cout<<shortestSupersequence(s1,s2,s1.size(),s2.size());
}