#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX 10
#define INFINITY 999
int a,b,u,v,n,i,j,ne=1;
int min,mincost=0,visited[10]={0};

void createMatrix(int G[MAX][MAX],int n){
	printf("\nEnter the adjacency matrix:\n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&G[i][j]);
			if(G[i][j]==0)
				G[i][j]=INFINITY;
		}
	}
}
void Prims(int cost[MAX][MAX],int n){
	visited[1]=1;
	printf("\n");
	while(ne < n){
		for(i=1,min=INFINITY;i<=n;i++)
		for(j=1;j<=n;j++)
		if(cost[i][j]< min)
		if(visited[i]!=0){
			min=cost[i][j];
			a=u=i;
			b=v=j;
		}
		if(visited[u]==0 || visited[v]==0){
			printf("\n Edge %d:(%d %d) cost:%d",ne++,a,b,min);
			mincost+=min;
			visited[b]=1;
		}
		cost[a][b]=cost[b][a]=INFINITY;
	}
}
int main(){
	int n,G[MAX][MAX];
	printf("Enter the no. of vertices:");
	scanf("%d",&n);
	createMatrix(G,n);
	
	clock_t et,st;
	double ts;
	et=clock();
	Prims(G,n);
	st=clock();
	ts=(double)(et-st)/CLOCKS_PER_SEC;
	printf("\ntime is %e\n",ts);
	
	printf("\nMinimum cost = %d\n",mincost);
	return 0;
}

