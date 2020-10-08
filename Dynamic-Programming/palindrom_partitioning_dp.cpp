/*
	Given a string, a partitioning of the string is a palindrome 
	partitioning if every substring of the partition is a palindrome. 
	For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. 
	Determine the fewest cuts needed for a palindrome partitioning of a given string. 
	For example, minimum of 3 cuts are needed for “ababbbabbababa”. 
	The three cuts are “a|babbbab|b|ababa”. If a string is a palindrome, 
	then minimum 0 cuts are needed. If a string of length n containing 
	all different characters, then minimum n-1 cuts are needed.
*/
#include<bits/stdc++.h>
using namespace std;

int solve(string s)
{
	int n=s.size();
	
	bool p[n][n];
	int c[n][n];
	
	for(int i=0;i<n;i++)
	{
		p[i][i]=true;
		c[i][i]=0;
	}
	
	for(int L=2;L<=n;L++)
	{
		for(int i=0 ; i < n-L+1 ; i++)
		{
			int j=i+L-1;
			if(L==2)
				p[i][j]=(s[i]==s[j]);
			else
				p[i][j]=(s[i]==s[j])&&p[i+1][j-1];
			
			if(p[i][j]==true)
				c[i][j]=0;
			else
			{
				c[i][j] = INT_MAX;
				for(int k=i;k<=j-1;k++)
					c[i][j]=min(c[i][j],1+c[i][k]+c[k+1][j]);
				
			}
			
		}
	}
	
	return c[0][n-1];
}


int main()
{
		string s="geek";
		
		cout<<solve(s);
}