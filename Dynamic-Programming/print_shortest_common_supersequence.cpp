//program to print shortest common supersequence

#include<bits/stdc++.h>
using namespace std;

string printSCS(string s1,string s2,int n1,int n2)
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
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}

	
	int i=n1,j=n2;
	string ret="";
	while(i>0&&j>0)
	{
	
		if(s1[i-1]==s2[j-1])
		{
		
			ret.push_back(s1[i-1]);
			i--;
			j--;
		}
		else
		{
			if(dp[i-1][j]>dp[i][j-1])
			{
				
				ret.push_back(s1[i-1]);
				
				i--;
			}
			else
			{
				
				ret.push_back(s2[j-1]);
				j--;
			}
			
		}
	}
	while(i>0)
	{
		ret.push_back(s1[i-1]);
		i--;
	}
	while(j>0)
	{
		ret.push_back(s2[j-1]);
		j--;
	}
	reverse(ret.begin(),ret.end());
	return ret;
}

int main()
{
	string s1="AGGTAB";
	string s2="GXTXAYB";
	
	cout<<printSCS(s1,s2,s1.size(),s2.size());
}