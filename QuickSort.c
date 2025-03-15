#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partion(int a[],int low,int high){
	int v=a[low],i=low+1,j=high;
	while(i<=j){
		while(a[i]<=v){
			i++;
		}
		while(a[j]>v){
			j--;
		}
		if(i<j){
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[j],&v);
	return j;
}
void Quicksort(int a[],int low,int high){
	if(high<=low)
		return;
	int j=partion(a,low,high);
	Quicksort(a,low,j-1);
	Quicksort(a,j+1,high);
	
}
int main(){
	int *a,n;
	clock_t st,et;
	double ts;
	printf("eneter size of array\n");
	scanf("%d",&n);
	a=(int*)malloc(sizeof(int)*n);
	printf("random numbers are\n");
	for(int k=0;k<n;k++){
		a[k]=k+1;
		printf("%d ",a[k]);
	}
	printf("\n");
	st=clock();
	Quicksort(a,0,n-1);
	et=clock();
	ts=(double)(et-st)/CLOCKS_PER_SEC;
	printf("sorted numbers are");
	for(int k=0;k<n;k++){
		printf("%d ",a[k]);
	}
	printf("\n");
	printf("the time taken is %f second \n",ts);
	return 0;
}


