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

void FloydWarshall(int graph[MAX][MAX],int n){
  	int matrix[n][n], i, j, k;

  	for(i=0;i<n;i++)
    	for(j=0;j<n;j++)
      		matrix[i][j] = graph[i][j];

  // Adding vertices individually
  	for(k=0;k<n;k++){
    	for(i=0;i<n;i++){
      		for(j=0;j<n;j++){
        		if(matrix[i][k]+matrix[k][j]<matrix[i][j])
          			matrix[i][j]=matrix[i][k]+matrix[k][j];
      		}
    	}
  	}
  	for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
      		if(matrix[i][j] == INFINITY)
        		printf("%4s", "INFINITY");
      		else
        		printf("%4d", matrix[i][j]);
    	}
    printf("\n");
  	}
}
int main(){
	int A[1000],n,G[MAX][MAX];
	printf("Enter no. of vertices:");
	scanf("%d",&n);
	createMatrix(G,n);
	
	clock_t et,st;
	double ts;
	et=clock();
	FloydWarshall(G,n);
	st=clock();
	ts=(double)(et-st)/CLOCKS_PER_SEC;
	printf("\n\ntime is %e\n\n",ts);
}
