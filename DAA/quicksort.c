#include<time.h>
#include<stdio.h>
#include<stdlib.h>

void createArray(int A[],int n){
	for(int i=0;i<n;i++){
		A[i]=rand();
	}
}
int swap(int *a, int *b){
	int t= *a;
	*a=*b;
	*b=t;
}
void printArray(int A[],int n){
	for(int i=0;i<n;i++){
		printf("%d,",A[i]);
	}
}
int partation(int A[],int l,int h){
	int i=l+1, j=h,pivot=A[l];
	while(i<=j){
		while(A[i]<=pivot){
			i++;
		}
		while(A[j]>pivot){
			j--;
		}
		if(i<j){
			swap(&A[i],&A[j]);
		}
	}
	swap(&A[l],&A[j]);
	return j;
}
void quicksort(int A[],int l, int h){
	if(l<h){
		int j=partation(A,l,h);
		quicksort(A,l,j-1);
		quicksort(A,j+1,h);
	}
}
int main(){
	int A[1000],n;
	printf("Enter the number of data you want to store:");
	scanf("%d",&n);
	
	createArray(A,n);
	
	printf("Unsorded data list:\n");
	printArray(A,n);
	
	clock_t et,st;
	double ts;
	et=clock();
	quicksort(A,0,n-1);
	st=clock();
	ts=(double)(et-st)/CLOCKS_PER_SEC;
	printf("\n\ntime is %e\n\n",ts);
	
	printf("Sorded data list:\n");
	printArray(A,n);
	return 0;
}
