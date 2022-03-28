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
 int sequentialsearch(int A[],int n,int key){
 	int i;
 	for(i=0;i<n;i++){
 		if(A[i]==key){
 			return i;
		 }
	 }
	 return -1;
 }
int main(){
	int A[1000],n,key,skey;
	printf("Enter the number of data you want to store:");
	scanf("%d",&n);
	
	createArray(A,n);
	
	Insertionsort(A,n);
	printf("Sorded data list:\n");
	printArray(A,n);
	
	printf("\nEnter the key you want to search:");
	scanf("%d",&key);
	
	clock_t et,st;
	double ts;
	et=clock();
	skey=sequentialsearch(A,n,key);
	st=clock();
	ts=(double)(et-st)/CLOCKS_PER_SEC;
	printf("\n\ntime is %e\n\n",ts);
	if(skey==-1){
		printf("Key not found.\n");
	}
	else{
		printf("Key found at %d.\n",skey);
	}
	return 0;
}
