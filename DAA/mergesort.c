#include<time.h>
#include<stdio.h>
#include<stdlib.h>
int B[1000];
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
int merge(int A[],int l,int m,int h){
	int i=l,j=m+1,k=l;
	while(i<=m && j<=h){
		if(A[i]<=A[j]){
			B[k++]=A[i++];
		}
		else{
			B[k++]=A[j++];
		}
	}
	while(i<=m){
		B[k++]=A[i++];
	}
	while(j<=h){
		B[k++]=A[j++];
	}
	for(k=l;k<=h;k++){
		A[k]=B[k];
	}
}

void mergesort(int A[],int l,int h){
	if(l<h){
		int mid=(l+h)/2;
		mergesort(A,l,mid);
		mergesort(A,mid+1,h);
		merge(A,l,mid,h);
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
	mergesort(A,0,n-1);
	st=clock();
	ts=(double)(et-st)/CLOCKS_PER_SEC;
	printf("\n\ntime is %e\n\n",ts);
	
	printf("Sorded data list:\n");
	printArray(A,n);
	return 0;
}
