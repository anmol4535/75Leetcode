// Question : Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
//You must implement a solution with a linear runtime complexity and use only constant extra space.

#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
        int x = 0;
        for(auto it : nums){
            x ^= it;
        } 
        return x;
    }