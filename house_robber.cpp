#include<iostream>
#include<vector>
using namespace std;

int rob(vector<int>& nums) {
	int dp[1000];
	int i,len;
	len = nums.size();
	if(len == 0)
	    return 0;
	dp[0] = 0;
	dp[1] = nums.at(0);
	cout<<"nums[0]  ="<<nums[0]<<endl;
	for(i=2;i<len;i++){
	    dp[i] = max(dp[i-1],dp[i-2]+nums.at(i-1));
	}
	dp[len] = max(dp[len-1],dp[len-2]+nums[len-1]);
	return dp[len];
}

int main(){
	vector<int> laser;
	laser.push_back(0);
	cout<<rob(laser);	
}
