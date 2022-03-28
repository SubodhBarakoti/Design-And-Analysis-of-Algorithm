#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#define INFINITY 9999
#define MAX 10

void createMatrix(int G[MAX][MAX],int n){
	printf("\nEnter the adjacency matrix:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&G[i][j]);
		}
	}
}
void Dijkstra(int Graph[MAX][MAX], int n, int start) {
  	int cost[MAX][MAX], distance[MAX], pred[MAX];
  	int visited[MAX], count, mindistance, nextnode, i, j;
 	 // Creating cost matrix
  	for(i=0;i<n;i++){
  		for (j=0;j<n;j++){
  			if(Graph[i][j]==0){
  				cost[i][j]=INFINITY;
		}
      	else{
      		cost[i][j] = Graph[i][j];
			}
		}
	}
	for (i=0;i<n;i++){
	    distance[i] = cost[start][i];
	    pred[i] = start;
	    visited[i] = 0;
	}
 	distance[start] = 0;
  	visited[start] = 1;
  	count = 1;
  	while(count<n-1){
    	mindistance = INFINITY;
	    for(i=0;i<n;i++)
	      	if (distance[i]<mindistance && !visited[i]){
		        mindistance = distance[i];
		        nextnode = i;
	      	}
	    visited[nextnode]=1;
	    for(i=0;i<n;i++)
	      if(!visited[i])
	        if(mindistance + cost[nextnode][i] < distance[i]){
	          	distance[i] = mindistance + cost[nextnode][i];
	          	pred[i] = nextnode;
	        }
	    count++;
  	}
  // Printing the distance
  	for (i=0;i<n;i++)
    	if (i!=start){
      		printf("\nDistance from source to %d: %d", i, distance[i]);
    	}
}

int main(){
	int A[1000],n,u,G[MAX][MAX];
	printf("Enter no. of vertices:");
	scanf("%d",&n);
	createMatrix(G,n);
	printf("\nEnter the starting node:");
	scanf("%d",&u);
	
	clock_t et,st;
	double ts;
	et=clock();
	Dijkstra(G,n,u);
	st=clock();
	ts=(double)(et-st)/CLOCKS_PER_SEC;
	printf("\n\ntime is %e\n\n",ts);
}
