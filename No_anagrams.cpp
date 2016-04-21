#include<iostream>
using namespace std;

int main(){
	string real,seal;
	cout<<"Enter the main string\n";
	cin>>real;
	cout<<"Enter the other string\n";
	cin>>seal;

	long long len_s,len_r,sum=0,mul=1,i,j;
	len_s = seal.length();
	len_r = real.length();

	for(i=0;i<len_s;i++){
		sum = sum + (long long)seal[i];
		mul = mul*(long long)seal[i];
	}


	long long occur=0,sum1=0,mul1=1;
	for(i=0;i<len_r-len_s+1;i++){
		for(j=i;j<i+len_s;j++){
			sum1 = sum1 + (long long)real[j];
			mul1 = mul1 * (long long)real[j];
		}

		if(sum1 == sum && mul1 == mul)
			occur++;

		sum1 = 0;
		mul1 = 1;
	}

	cout<<"So the total number of occurence of an anagram in string is"<<occur<<endl;
}
