//Solving knapsack problem with topdown approach


int knapsack(int val[],int wt[],int W,int N)
{
	int arr[N+1][W+1];
	memset(arr,0,sizeof(arr));
	for(int i=1;i<N+1;i++)
	{
		for(int j=1;j<W+1;j++)
		{
			if(wt[i-1]<=j)
			{
				arr[i][j]=max(val[i]+arr[i-1][j-wt[i-1]],arr[i-1][j]);
				
			}
			else
			{
				arr[i][j]=arr[i-1][j];
			}
		}
	}
	
	return arr[N][W];
}
