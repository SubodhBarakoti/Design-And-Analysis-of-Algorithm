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
void selectionsort(int A[],int n){
	int j,i,min;
	for(j=0;j<n-1;j++){
		min =j;
		for(i=j+1;i<n;i++){
			if(A[i]<A[min]){
				min=i;
			}
		}
		if(j!=min){
			swap(&A[min],&A[j]);
		}
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
	selectionsort(A,n);
	st=clock();
	ts=(double)(et-st)/CLOCKS_PER_SEC;
	printf("\n\ntime is %e\n\n",ts);
	
	printf("Sorded data list:\n");
	printArray(A,n);

	return 0;
}
