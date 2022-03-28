#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
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
int partation(int A[],int l,int h){
	int pivot=A[l];
	int i=l,j=h+1;
	int temp;
	while(i<j){
		do{
			i++;
		}while(A[i]<=pivot);
		do{
			j--;
		}while(A[j]>pivot);
		if(i<j){
			swap(&A[i],&A[j]);
		}
	}
	swap(&A[l],&A[j]);
	return j;
}
int randompartation(int A[],int l,int h){
	int k=(rand()%(h-l+1))+l;
	swap(&A[l],&A[k]);
	return partation(A,l,h);
}

int OrderStatistic(int A[],int l, int h, int i){
		if(l==h){
			return A[l];
		}
		int j=randompartation(A,l,h);
		int k=j-l+1;
		if(i<=k){
			return OrderStatistic(A,l,j-1,i);
		}
		else{
			return OrderStatistic(A,j+1,h,i-k);
		}
	}

int main(){
	int A[1000],n,i;
	printf("Enter the number of data you want to store:");
	scanf("%d",&n);
	
	createArray(A,n);
	
	printf("Unsorded data list:\n");
	printArray(A,n);
	
	printf("\nEnter the term you want to find out: ");
	scanf("%d",&i);
	
	clock_t et,st;
	double ts;
	et=clock();
	int value=OrderStatistic(A,0,n-1,i);
	st=clock();
	ts=(double)(et-st)/CLOCKS_PER_SEC;
	printf("time is %e\n",ts);
	
	printf("The %d term is %d.",i,value);
	return 0;
}