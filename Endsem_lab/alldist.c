#include<stdio.h>
#include<stdbool.h>
#include<limits.h>


void addMatrix(int v,int matrix[][v+1],int start,int end,int val)
{
	matrix[start][end]=val;
	matrix[end][start]=val;
}

int minDistance(int distance[],bool set[],int v)
{
	int min=INT_MAX,minIndex;

	for(int i=1;i<=v;i++)
	{
		if(set[i]==false && distance[i]<min)
		{
			minIndex=i;
			min=distance[i];
		}
	}

	return minIndex;
}

void dijsktra(int v,int matrix[][v+1],int alldist[][v+1],int src)
{
	int distance[v+1];
	bool set[v+1];

	for(int i=1;i<=v;i++)
	{
		distance[i]=INT_MAX;
		set[i]=false;
	}

	distance[src]=0;

	for(int count=0;count<v-1;count++)
	{
		int u=minDistance(distance,set,v);

		set[u]=true;

		for(int i=1;i<=v;i++)
		{
			if(!set[i] && matrix[u][i] && distance[u]!=INT_MAX && distance[u]+matrix[u][i]<distance[i])
				distance[i]=distance[u]+matrix[u][i];
		}
	}

	for(int i=1;i<=v;i++)
		alldist[src][i]=distance[i];
}

int main()
{
	int v,e,start,end,val,t,a,b;
	scanf("%d%d",&v,&e);

	int matrix[v+1][v+1];
	int alldist[v+1][v+1];

	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=v;j++)
			matrix[i][j]=0;
	}

	while(e--)
	{
		scanf("%d%d%d",&start,&end,&val);
		addMatrix(v,matrix,start,end,val);
	}

	for(int i=1;i<=v;i++)
		dijsktra(v,matrix,alldist,i);

	for(int i=1;i<=v;i++){
		for(int j=1;j<=v;j++){
			printf("%d ",alldist[i][j]);
		}

		printf("\n");
	}

}