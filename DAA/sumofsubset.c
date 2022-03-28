#include<stdio.h>
#include<time.h>
#define TRUE 1
#define FALSE 0
int inc[50],sum,n;

void swap(int *a, int *b){
	int t= *a;
	*a=*b;
	*b=t;
}
void Bubblesort(int A[],int n){
 	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(A[j]>A[j+1]){
				swap(&A[j],&A[j+1]);
			}
		}
	}
 }
void createArray(int A[],int n){
	printf("\nEnter %d numbers for the set: ", n);
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	Bubblesort(A,n);
}

int promising(int W[],int i,int wt,int total){
	return(((wt+total)>=sum)&&((wt==sum)||(wt+W[i+1]<=sum)));
}

void sumset(int W[],int i,int wt,int total){
	int j;
 	if(promising(W,i,wt,total)){
  		if(wt==sum){
   			printf("\n{");
   			for(j=0;j<=i;j++)
    			if(inc[j])
    				printf(" %d",W[j]);
   			printf(" }\n");
  		}
		else{
   			inc[i+1]=TRUE;
   			sumset(W,i+1,wt+W[i+1],total-W[i+1]);
   			inc[i+1]=FALSE;
   			sumset(W,i+1,wt,total-W[i+1]);
  		}
 	}
}
int main(){
	int i,j,n,temp,total=0, W[100];
	clock_t et,st;
	double ts;
	
 	printf("Enter the no. of the number used:");
 	scanf("%d",&n);
 	createArray(W,n);
 	printf("Enter the value of the sum:");
 	scanf("%d",&sum);
 	
 	for(i=0;i<n;i++)
  		total+=W[i];
  	
 	if(total<sum)
  		printf("\nSubset construction is not possible");
	else{
  		for(i=0;i<n;i++)
   			inc[i]=0;
  		printf("\nThe solution using backtracking is:\n");
  		et=clock();
		sumset(W,-1,0,total);
		st=clock();
		ts=(double)(et-st)/CLOCKS_PER_SEC;
		printf("\ntime is %e\n",ts);
 	}
 	return 0;
}
