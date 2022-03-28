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
void heapify(int A[],int n, int i){
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<n && A[left] > A[largest]){
		largest=left;
	}
	if(right<n && A[right]>A[largest]){
		largest=right;
	}
	if(largest!=i){
		swap(&A[i],&A[largest]);
		heapify(A,n,largest);
	}
}
void Heapsort(int A[],int n){
	int i;
	for(i=(n/2)-1;i>=0;i--){
		heapify(A,n,i);
	}
	for(i=n-1;i>=0;i--){
		swap(&A[0],&A[i]);
		heapify(A,i,0);
	}
}

int main(){
	int A[1000],n,i;
	clock_t et,st;
	double ts;
	printf("Enter the number of data you want to store:");
	scanf("%d",&n);
	
	createArray(A,n);
	
	printf("Unsorded data list:\n");
	printArray(A,n);
	
	et=clock();
	Heapsort(A,n);
	st=clock();
	ts=(double)(et-st)/CLOCKS_PER_SEC;
	printf("\n\ntime is %e\n\n",ts);
	
	printf("Sorded data list:\n");
	printArray(A,n);

	return 0;
}
