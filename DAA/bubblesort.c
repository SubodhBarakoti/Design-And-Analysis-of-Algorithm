#include<time.h>
#include<stdio.h>
#include<stdlib.h>
int swap(int *a, int *b){
	int t= *a;
	*a=*b;
	*b=t;
}
void createArray(int A[],int n){
	for(int i=0;i<n;i++){
		A[i]=rand();
	}
}
void printArray(int A[],int n){
	for(int i=0;i<n;i++){
		printf("%d,",A[i]);
	}
}
 void Bubblesort(int A[],int n){
 	int i,j,temp;
 	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(A[j]>A[j+1]){
				swap(&A[j],&A[j+1]);
			}
		}
	}
	 
 }
int main(){
	int A[1000],n,i;
	printf("Enter the number of data you want to store:");
	scanf("%d",&n);
	
	createArray(A,n);
	
	printf("Unsorded data list:\n");
	printArray(A,n);
	
	clock_t et,st;
	double ts;
	et=clock();
	Bubblesort(A,n);
	st=clock();
	ts=(double)(et-st)/CLOCKS_PER_SEC;
	printf("\n\ntime is %e\n\n",ts);
	
	printf("Sorded data list:\n");
	printArray(A,n);
	return 0;
}
