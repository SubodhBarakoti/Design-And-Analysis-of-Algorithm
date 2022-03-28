#include<time.h>
#include<stdio.h>
#include<stdlib.h>

//without using recursion
int fibonacci(int n){
	int a=0,b=1,i=3,t;
	while(i<n){
		t=a+b;
		a=b;
		b=t;
		i++;
	}
	return b;
}

//using recursion

//int fibonacci(int n){
//	if(n==1){
//		return 0;
//	}
//	else if(n==2){
//		return 1;
//	}
//	else{
//		return fibonacci(n-1)+fibonacci(n-2);
//	}
//}
int main(){
	int n,fibo;
	printf("Enter n:");
	scanf("%d",&n);
	clock_t et,st;
	double ts;
	et=clock();
	fibo=fibonacci(n);
	st=clock();
	ts=(double)(et-st)/CLOCKS_PER_SEC;
	printf("time is %e\n",ts);
	printf("Fibonacci number of %dth term is: %d.",n,fibo);

	return 0;
}
