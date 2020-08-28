//longest common substring

#include<bits/stdc++.h>
using namespace std;

int LCS(string s1,string s2,int n1,int n2)
{
	int dp[n1+1][n2+1];
	for(int i=0;i<=n1;i++)
		dp[i][0]=0;
	
	for(int j=1;j<=n2;j++)
		dp[0][j]=0;
	
	for(int i=1;i<=n1;i++)
	{
		for(int j=1;j<=n2;j++)
		{
			if(s1[i]==s2[j])
				dp[i][j]=1+dp[i-1][j-1];
			else
				dp[i][j]=0;
		}
	}
	return dp[n1][n2];
}

int main()
{
	string s1="GeeksforGeeks";
	string s2="GeeksQuiz";
	cout<<LCS(s1,s2,s1.size(),s2.size());
}