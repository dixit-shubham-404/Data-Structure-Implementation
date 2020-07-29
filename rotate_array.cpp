/*
Given an unsorted array arr[] of size N, rotate it by D elements (clockwise). 

Input:
The first line of the input contains T denoting the number of testcases.
 First line of each test case contains two space separated elements, N denoting the size of the 
 array and an integer D denoting the number size of the rotation. Subsequent line will be the N space separated array elements.

Output:
For each testcase, in a new line, output the rotated array.

Constraints:
1 <= T <= 200
1 <= N <= 107
1 <= D <= N
0 <= arr[i] <= 105
*/


#include <iostream>
using namespace std;

int main() {
	//code
	int t,n,d;
	cin>>t;
	while(t>0)
	{
	    cin>>n>>d;
	    int arr[n];
	    for(int j=0,i=n-d;j<n;i=i%n,j++)
	    {
	        cin>>arr[i];
	        i++;
	    }
	    for(int i=0;i<n;i++)
	    {
	        cout<<arr[i]<<" ";
	    }
	    cout<<"\n";
	    t--;
	}
	return 0;
}