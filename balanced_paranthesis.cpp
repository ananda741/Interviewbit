#include<iostream>
#include<stack>
using namespace std;

int Matching(char first,char second){
	if(first == '(' && second == ')')
		return 1;
	else if(first == '{' && second == '}')
		return 1;
	else if(first == '[' && second == ']')
		return -1;
	else
		return 0;
}

int main(){
	stack<char> laser;
	int i,flag =1;
	string s;
	cout<<"Enter the string\n";
	cin>>s;
	
	for(i=0;s[i]!='\0';i++){
		if(s[i] == '(' || s[i] == '{' || s[i] == '[')
			laser.push(s[i]);
		else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
			if(Matching(laser.top(),s[i]))
				laser.pop();
			else if(!Matching(laser.top(),s[i])){
				flag = 0;
			}
		}
	}

	if(flag == 0 || !laser.empty()){
		cout<<"Not Balanced\n";
	}
	else
		cout<<"Balanced\n";
	return 0;
}
