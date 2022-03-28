#include<time.h>
#include<stdio.h>
#include<stdlib.h>
int max(int a, int b){ 
	return (a > b) ? a : b; 
	}
void createArray(int A[],int B[],int n){
	for(int i=0;i<n;i++){
		printf("Enter weight for P%d:",i);
		scanf("%d",&A[i]);
		printf("Enter profit for P%d:",i);
		scanf("%d",&B[i]);
	}
}
int knapsack(int W, int wt[], int val[], int n){
   int i, w;
   int K[n+1][W+1];
   for (i = 0; i <= n; i++){
       for (w = 0; w <= W; w++){
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
   return K[n][W];
}
int main(){
	int W[100],P[100],n,w,p;
	clock_t et,st;
	double ts;
	printf("Enter the number of data you want to store:");
	scanf("%d",&n);
	
	createArray(W,P,n);
	
	printf("Enter the maximum weight that the knapsack bag can carry:");
	scanf("%d",&w);
	
	et=clock();
	p=knapsack(w,W,P,n);
	st=clock();
	ts=(double)(et-st)/CLOCKS_PER_SEC;
	printf("\ntime is %e\n",ts);
	
	printf("\nThe maximum profit is: %d.",p);

	return 0;
}
