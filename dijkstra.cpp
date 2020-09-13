//Dijkstra Algorithm

#include<bits/stdc++.h>
using namespace std;

const int V=9;


void dijkstra(int graph[V][V],int start)
{
	bool visited[V];
	memset(visited,false,sizeof(visited));
	int distance[V];
	distance[start]=0;
	for(int i=0;i<V;i++)
	{
		distance[i]=99999;
	}
	distance[start]=0;
	for(int i=0;i<V;i++)
	{
		//finding node with minimun distance
		int min_dis=INT_MAX,node;
		for(int j=0;j<V;j++)
		{
			if(!visited[j]&&min_dis>distance[j])
			{
				min_dis=distance[j];
				node=j;
			}
		}
		//making the selected node marked
		visited[node]=true;
	
		for(int j=0;j<V;j++)
		{
			if(!visited[j]&&graph[node][j])
			{
				if(distance[j]>distance[node]+graph[node][j])
				{
					distance[j]=distance[node]+graph[node][j];
				}
			}
		}
	}
	
	for(int i=0;i<V;i++)
	{
		cout<<distance[i]<<" ";
	}
}

int main()
{
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
						
	dijkstra(graph,0);
}