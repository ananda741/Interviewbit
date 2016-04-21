#include<iostream>
#include<stack>
using namespace std;

int check(char ch){
	return (ch>= 'a' && ch<= 'z')||(ch>='A'&&ch<='Z');
}

int Prec(char ch){
	switch(ch){
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
	}
	return -1;
}

int main(){
	stack<char> laser;
	int i,k;
	string s,p;
	cout<<"Enter the string\n";
	cin>>s;
	for(i=0,k=-1;s[i]!='\0';i++){
		if(check(s[i]))
			p[++k] = s[i];
		else if(s[i]=='(')
			laser.push(s[i]);
		else if(s[i] == ')'){
			while(!laser.empty() && laser.top()!='('){
				p[++k] = laser.top();
				laser.pop();
			}
			if(!laser.empty() && laser.top()!='(')
				return -1;
			else
				laser.pop();
		}
		else{
			while(!laser.empty() && Prec(s[i])<=Prec(laser.top())){
				p[++k] = laser.top();
				laser.pop();
			}
			laser.push(s[i]);
		}
	}

	while(!laser.empty()){
		p[++k] = laser.top();
		laser.pop();
	}

	p[++k] = '\0';

	for(i=0;p[i]!='\0';i++)
		cout<<p[i];
	return 0;
}
