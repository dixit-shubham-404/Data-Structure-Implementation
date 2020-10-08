/*
Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome. 
For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. 
Determine the fewest cuts needed for a palindrome partitioning of a given string. 
For example, minimum of 3 cuts are needed for “ababbbabbababa”. The three cuts 
are “a|babbbab|b|ababa”. If a string is a palindrome, then minimum 0 cuts are needed. 
If a string of length n containing all different characters, then minimum n-1 cuts are needed.
*/

#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s,int i,int j)
{
	while(i<=j)
	{
		if(s[i]!=s[j])
			return false;
		
		i++;
		j--;
	}
	return true;
}

int solve(string s,int i,int j)
{
	if(i>=j)
		return 0;
	
	if(isPalindrome(s,i,j))
		return 0;
	
	int ans=INT_MAX;
	for(int k=i;k<=j-1;k++)
	{
		int temp=1+solve(s,i,k)+solve(s,k+1,j);
		ans=min(ans,temp);
		
	}
	
	return ans;
}

int main()
{
	string s="geek";
	int size=s.length();
	cout<<solve(s,0,size-1);
	
}