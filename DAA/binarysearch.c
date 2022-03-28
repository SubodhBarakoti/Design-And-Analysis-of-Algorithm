#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int swap(int *a, int *b){
	int t= *a;
	*a=*b;
	*b=t;
}
void Bubblesort(int A[],int n){
 	int i,j;
 	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(A[j]>A[j+1]){
				swap(&A[j],&A[j+1]);
			}
		}
	}	 
}
void createArray(int A[],int n){
	for(int i=0;i<n;i++){
		A[i]=rand();
	}
	Bubblesort(A,n);
}
void printArray(int A[],int n){
	for(int i=0;i<n;i++){
		printf("%d,",A[i]);
	}
}

//without recursion

//int Bsearch(int A[], int key,int n){
// 	int low=0, high=n-1,mid;
// 	while(low<=high){
// 		mid=(low+high)/2;
// 		if(key>A[mid]){
// 			low=mid+1;
//		 }
//		 else if(key<A[mid]){
//		 	high=mid-1;
//		 }
//		 else{
//		 	return mid;
//		 }
//	 }
//	 return -1;
// }

//with recursion
int Bsearch(int A[], int key,int low, int high){
 	if(low>high){
 		return -1;
	 }
	 int mid;
	 mid=(low+high)/2;
	 if(A[mid]<key){
	 	return(Bsearch(A,key,mid+1,high));
	 }
	 else if(A[mid]>key){
	 	return(Bsearch(A,key,low,mid-1));
	 }
	 else{
	 	return mid;
	 }
 }

int main(){
	int A[1000],n,key,i,skey;
	clock_t et,st;
	double ts;
	printf("Enter the number of data you want to store:");
	scanf("%d",&n);
	createArray(A,n);
	
	printf("\nThe data stored is:\n");
	printArray(A,n);
	
	printf("\nEnter the key you want to search:");
	scanf("%d",&key);
	et =clock();
	skey = Bsearch(A,key,0,n-1);
	st=clock();
	ts=(double)(et-st)/CLOCKS_PER_SEC; 
	printf("\ntime is %e",ts);		//CLOCK_PER_SEC is macro i.e. a inline function that return no of time system ticks per second
	if(skey==-1){
		printf("\nKey not found");
	}
	else{
		printf("\n%d found in %d position.",key,skey);
	}
	
	return 0;
}
