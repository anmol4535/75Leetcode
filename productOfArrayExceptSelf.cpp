// Question : Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
// You must write an algorithm that runs in O(n) time and without using the division operation.

#include <bits/stdc++.h>
using namespace std;

 vector<int> productExceptSelf(vector<int>& nums) {
        int z = 0;
        vector<int> ans(nums.size(),0);
        int pro = 1;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i]!=0)
                pro *= nums[i];
            if(nums[i] == 0) z++;
        }

        if(z>1) return ans;

        for(int i = 0; i< nums.size(); i++){
            if(nums[i] != 0 && z==0 ){
                ans[i] = pro/nums[i];
            }
                
            if(nums[i] == 0){
                ans[i] = pro;
            }
        }
        return ans;
    }

 