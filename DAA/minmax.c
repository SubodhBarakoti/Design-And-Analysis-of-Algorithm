#include<time.h>
#include<stdio.h>
#include<stdlib.h>
int max, min;
void createArray(int A[],int n){
	for(int i=1;i<=n;i++){
		A[i]=rand();
	}
}
void printArray(int A[],int n){
	for(int i=1;i<=n;i++){
		printf("%d,",A[i]);
	}
}
void maxmin(int A[],int i, int j){
 	int max1, min1, mid;
 	if(i==j){
  		max = min = A[i];
 	}
 	else{
  		if(i == j-1){
		   if(A[i] <A[j]){
		    	max = A[j];
		    	min = A[i];
		   	}
		   else{
		    	max = A[i];
		    	min = A[j];
			}
  		}
  		else{
		   	mid = (i+j)/2;
		   	maxmin(A,i,mid);
		   	max1 = max; min1 = min;
		   	maxmin(A,mid+1,j);
		   	if(max <max1)
		    	max = max1;
		   	if(min > min1)
		    	min = min1;
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
	max = A[0];
	min = A[0];
	printf("Unsorded data list:\n");
	printArray(A,n);
	
	et=clock();
	maxmin(A,1,n);
	st=clock();
	ts=(double)(et-st)/CLOCKS_PER_SEC;
	printf("\n\ntime is %e\n\n",ts);
	
	printf ("Minimum element in an array : %d\n", min);
	printf ("Maximum element in an array : %d\n", max);
	return 0;
}