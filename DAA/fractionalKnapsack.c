#include<time.h>
#include<stdio.h>
#include<stdlib.h>
float X[100];
void swap(int *a, int *b){
	int t= *a;
	*a=*b;
	*b=t;
}
void swapfloat(float *a, float *b){
	float t= *a;
	*a=*b;
	*b=t;
}
void createArray(int A[],int B[],int n){
	for(int i=0;i<n;i++){
		printf("Enter weight for P%d:",i);
		scanf("%d",&A[i]);
		printf("Enter profit for P%d:",i);
		scanf("%d",&B[i]);
	}
}
 void Bubblesort(float A[],int B[],int C[],int n){
 	int i,j,temp;
 	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(A[j]<A[j+1]){
				swapfloat(&A[j],&A[j+1]);
				swap(&B[j],&B[j+1]);
				swap(&C[j],&C[j+1]);
			}
		}
	}
	 
 }
float knapsack(int W[], int P[], int n, int w){
 	int i,weight,profit=0;
 	float N[100];
 	for(i=0;i<n;i++){
		N[i]=(float)P[i]/W[i];
		X[i]=0;
	}
	Bubblesort(N,W,P,n);
	i=0,weight=0;
	while(weight<w){
		if((weight+W[i])<w){
			weight+=W[i];
			X[i]=1;
		}
		else{
			X[i]=(float)(w-weight)/W[i];
			weight=w;
		}
		i++;
	}
	for(i=0;i<n;i++){
		profit=profit+X[i]*P[i];
	}
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
	p=knapsack(W,P,n,w);
	st=clock();
	ts=(double)(et-st)/CLOCKS_PER_SEC;
	printf("\ntime is %e\n",ts);
	
	printf("\nThe maximum profit is: %d.",p);

	return 0;
}
