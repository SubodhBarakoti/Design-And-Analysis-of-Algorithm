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
 void Insertionsort(int A[],int n){
 	int i,j,temp;
 	for(i=1;i<n;i++){
 		temp=A[i];
 		j=i-1;
 		while(j>=0 && A[j]>temp){
 			A[j+1]=A[j];
 			j--;
		 }
		 A[j+1]=temp;
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
	Insertionsort(A,n);
	st=clock();
	ts=(double)(et-st)/CLOCKS_PER_SEC;
	printf("\n\ntime is %e\n\n",ts);
	
	printf("Sorded data list:\n");
	printArray(A,n);
	return 0;
}
