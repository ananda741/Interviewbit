/*
	Given an array of integers, return indices of the two numbers such that they add up to a specific target.

	You may assume that each input would have exactly one solution.

	Example:

	Given nums = [2, 7, 11, 15], target = 9,

	Because nums[0] + nums[1] = 2 + 7 = 9,
	return [0, 1].
*/

#include<iostream>
#include<map>
using namespace std;

    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> laser;
        vector<int> maser;
        int i,len = nums.size();
        for(i = 0;i<len;i++){
           
           if(laser.find(target-nums[i])!=laser.end()){
               maser.push_back(laser[target-nums[i]]);
               maser.push_back(i+1);
           }
           
            if(laser.find(nums[i]) == laser.end())
                laser[nums[i]] = i+1;
        }
        
     
        return maser;
    }


int main(){
	int i,size,val,target;
	vector<int> arr;
	cin>>size;
	for(i=0;i<size;i++){
		cin>>val;
		arr.push_back(val);
	}
	
	cin>>target;
	vector<int> answer = twoSum(arr,target);

	cout<<answer[0]<<" "<<answer[1]<<endl;
}

