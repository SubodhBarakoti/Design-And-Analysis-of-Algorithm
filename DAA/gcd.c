//GCD algorithm
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//with recursion

//int gcd(int a, int b){
//	if(a==0){
//		return b;
//	}
//	else if(b==0){
//		return a;
//	}
//	else{
//		return gcd(b,a%b);
//	}
//}


//without recursion
int gcd(int a, int b){
	while(a!=b){
		if(a>b){
			a-=b;
		}
		else{
			b-=a;
		}
	}
	return b;
}
int main(){
	int a,b,c;
	clock_t et,st;
	double ts;
	printf("Enter the value of a:");
	scanf("%d",&a);
	printf("Enter the value of b:");
	scanf("%d",&b);
	
	et=clock();
	c=gcd(a,b);
	st=clock();
	ts=(double)(et-st)/CLOCKS_PER_SEC;
	
	printf("Gcd is: %d.\n",c);
	printf("time is %e.",ts);
	return 0;
}
