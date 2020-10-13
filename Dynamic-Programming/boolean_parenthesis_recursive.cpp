/*
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.
*/

#include<bits/stdc++.h>
using namespace std;

int solve(string s,int i,int j,bool isT)
{
	//cout<<"i="<<i<<" j="<<j<<endl;
	if(i>j)
		return false;
	
	if(i==j)
	{
		if(isT)
			return s[i]=='T';
		else
			return s[i]=='F';
	}
	int ans=0;
	for(int k=i+1;k<=j-1;k+=2)
	{
		int lT=solve(s,i,k-1,true);
		int lF=solve(s,i,k-1,false);
		int rT=solve(s,k+1,j,true);
		int rF=solve(s,k+1,j,false);
		
		if(s[k]=='&')
		{
			if(isT)
			{
				ans=ans+lT*rT;
			}
			else
			{
				ans=ans+lF*rF+lF*rT+lT*rF;
			}
		}
		else if(s[k]=='|')
		{
			if(isT)
			{
				ans=ans+lT*rT+lT*rF+lF*rT;
			}
			else{
				ans=ans+lF*rF;
			}
			
		}
		else
		{
			if(isT)
			{
				ans=ans+lF*rT+lT*rF;
			}
			else
			{
				ans=ans+lF*rF+lT*rT;
			}
		}
	}
	return ans;
}

int main()
{
	string s="T|T&F^T";
	
	cout<<solve(s,0,s.size()-1,true);
}