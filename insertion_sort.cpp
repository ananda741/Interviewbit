#include<iostream>
using namespace std;

void insertion_sort(int *A,int n){
	int value,hole,i;
	for(i=1;i<n;i++){
		value = A[i];
		hole = i;
		while(hole>0 && A[hole-1]>value){
			A[hole] = A[hole-1];
			hole--;
		}
		A[hole] = value;
	}
}

int main(){
	int arr[]={5,3,2,1,4,8,6},n,i;
	n = sizeof(arr)/sizeof(arr[0]);
	insertion_sort(arr,n);
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";

	cout<<endl;
	return 0; 
}
