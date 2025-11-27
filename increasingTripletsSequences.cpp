// Question : Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

#include <bits/stdc++.h>
using namespace std;

bool increasingTriplet(vector<int>& nums) {
        int f = INT_MAX , s = INT_MAX;

        for(auto it : nums) {
            if(it <= f) f = it;
            else if(it <= s) s= it;
            else return true;
        }
        return false;
    }

//  this code have time complexity of o(n) and space complexity of o(1).
// this question is good for problem solving because this have that equation to find which three index you gone choose
// Looking forward to solve more this type of problem.