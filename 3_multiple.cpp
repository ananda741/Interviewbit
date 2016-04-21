#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;

int populate(queue<int> &queue0,queue<int> &queue1,queue<int> &queue2,int *arr){
	int i=0;
	while(!queue0.empty()){
		arr[i] = queue0.front();
		queue0.pop();
		i++;
	}
	while(!queue1.empty()){
		arr[i] = queue1.front();
		queue1.pop();
		i++;
	}
	while(!queue2.empty()){
		arr[i] = queue2.front();
		queue2.pop();
		i++;
	}

	sort(arr,arr+i,greater<int>());
	return i;
}

int Multiple_3(int *arr,int n){
	int i,sum=0,k;	
	queue<int> queue0,queue1,queue2;
	sort(arr,arr+n);
	for(i=0;i<n;i++){
		if(arr[i]%3==0)
			queue0.push(arr[i]);
		else if(arr[i]%3==1)
			queue1.push(arr[i]);
		else
			queue2.push(arr[i]);
		sum+=arr[i];
	}

	if(sum%3==1){
		queue1.pop();
		if(queue1.empty()){
			if(queue2.size()<2){
				return -1;
			}
		}
	}

	if(sum%3==2){
		queue2.pop();
		if(queue2.empty()){
			if(queue1.size()<2){
				return -1;
			}
		}
	}

	k = populate(queue0,queue1,queue2,arr);
	
	for(i=0;i<k;i++)
		cout<<arr[i];
	cout<<endl;

	return 1;
	
}


int main(){
	 int arr[] = {8, 1, 9,4};
    	 int size = sizeof(arr)/sizeof(arr[0]);

	if(Multiple_3(arr,size)==-1)
		cout<<"Not possible\n";

	return 0;
}
