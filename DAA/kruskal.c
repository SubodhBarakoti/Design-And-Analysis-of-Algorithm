#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX 10
#define INFINITY 999
int i,j,k,a,b,u,v,ne=1;
int min,mincost=0,parent[MAX];

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

int find(int i){
	while(parent[i])
	i=parent[i];
	return i;
}
int uni(int i,int j){
	if(i!=j){
		parent[j]=i;
		return 1;
	}
	return 0;
}
void Kruskal(int cost[MAX][MAX],int n){
	printf("The edges of Minimum Cost Spanning Tree are\n");
	while(ne < n){
		for(i=1,min=INFINITY;i<=n;i++){
			for(j=1;j <= n;j++){
				if(cost[i][j] < min){
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v)){
			printf("%d edge (%d,%d) =%d\n",ne++,a,b,min);
			mincost +=min;
		}
		cost[a][b]=cost[b][a]=INFINITY;
	}
}
int main(){
	int n,G[MAX][MAX];
	printf("\nEnter the no. of vertices:");
	scanf("%d",&n);
	createMatrix(G,n);
	
	clock_t et,st;
	double ts;
	et=clock();
	Kruskal(G,n);
	st=clock();
	ts=(double)(et-st)/CLOCKS_PER_SEC;
	printf("\n\ntime is %e\n\n",ts);
	
	printf("\n\tMinimum cost = %d\n",mincost);
	return 0;
}

