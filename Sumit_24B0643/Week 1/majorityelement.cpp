#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums){
    int c=0;
    for (int i=0; i<nums.size(); i++){
        for (int j=i; j<nums.size(); j++){
            if (nums[i]==nums[j]){
                c++;
            }
        }
        if (c>nums.size()/2){
            return nums[i];
        }
        else{
            c=0;
        }
    }
    return -1;
}