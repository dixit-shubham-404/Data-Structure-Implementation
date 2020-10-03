/*
Given an expression which contains numbers and two operators ‘+’ and ‘*’, we need to find maximum and 
minimum value which can be obtained by evaluating this expression by different parenthesization.
Examples:

Input  : expr = “1+2*3+4*5” 
Output : Minimum Value = 27, Maximum Value = 105 
Explanation:
Minimum evaluated value = 1 + (2*3) + (4*5) = 27
Maximum evaluated value = (1 + 2)*(3 + 4)*5 = 105
*/




#include<bits/stdc++.h>
using namespace std;

int maximum(string str)
{
	vector<int> val;
	vector<char> op;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='+')
			op.push_back(str[i]);
		else if(str[i]=='*')
			op.push_back(str[i]);
		else
			val.push_back(str[i]-48);
	}
	int dp[val.size()][val.size()];
	
	
	for(int i=0;i<val.size();i++)
	{
		for(int j=0;j<val.size();j++)
		{
			dp[i][j]=0;
			if(i==j)
				dp[i][j]=val[i];
		}
	}
	for(int L=2;L<=val.size();L++)
	{
		
		for(int i=0;i<val.size()-L+1;i++)
		{
			int j=i+L-1;
			//if(j==val.size())
			//	continue;
			for(int k=i;k<=j-1;k++)
			{
				int q;
				int a=(i+j)/2;
				if(op[k]=='+')
					q=dp[i][k]+dp[k+1][j];
				else
					q=dp[i][k]*dp[k+1][j];
				
				dp[i][j]=max(q,dp[i][j]);
			}
		}
	}
	
	return dp[0][val.size()-1];
}



int minimum(string str)
{
	vector<int> val;
	vector<char> op;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='+')
			op.push_back(str[i]);
		else if(str[i]=='*')
			op.push_back(str[i]);
		else
			val.push_back(str[i]-48);
	}
	int dp[val.size()][val.size()];
	
	
	for(int i=0;i<val.size();i++)
	{
		for(int j=0;j<val.size();j++)
		{
			dp[i][j]=INT_MAX;
			if(i==j)
				dp[i][j]=val[i];
		}
	}
	for(int L=2;L<=val.size();L++)
	{
		
		for(int i=0;i<val.size()-L+1;i++)
		{
			int j=i+L-1;
			//if(j==val.size())
			//	continue;
			for(int k=i;k<=j-1;k++)
			{
				int q;
				int a=(i+j)/2;
				if(op[k]=='+')
					q=dp[i][k]+dp[k+1][j];
				else
					q=dp[i][k]*dp[k+1][j];
				
				dp[i][j]=min(q,dp[i][j]);
			}
		}
	}
	
	return dp[0][val.size()-1];
}

int main()
{
	string str="1+2*3+4*5";
	cout<<"Minimum value: "<<minimum(str)<<endl;
	cout<<"Maximum value: "<<maximum(str)<<endl;
}