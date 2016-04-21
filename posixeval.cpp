#include<iostream>
#include<stack>
using namespace std;

int check(char ch){
	int num;
	if(ch>= '0' && ch<='9')
		num = (int)ch - 48;
	else
	    return 0;
	return num;
}

int eval(stack<int> &laser ,char ch){
	int a,b;
	a = laser.top();
	laser.pop();
	b = laser.top();
	laser.pop();
	switch(ch){
		case '+': a = a+b;
			  laser.push(a);
			  break;
		case '-': a = b-a;
			  laser.push(a);
			  break;
		case '*': a = a*b;
			  laser.push(a);
			  break;
		case '/': a = a/b;
			  laser.push(a);
			  break;
		case '^': a = a^b;
			  laser.push(a);
	}
	return -1;
}

int main(){
	stack<int> laser;
	int i,len;
	string s;
	cout<<"Enter the string\n";
	cin>>s;
	len = s.length();

	for(i=0;i<len;i++){
		if(check(s[i]))
			laser.push(check(s[i]));
		else{
			eval(laser,s[i]);
		}
	}
	cout<<laser.top();
}
