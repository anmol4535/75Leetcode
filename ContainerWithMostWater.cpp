// Question : You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.
// Notice that you may not slant the container.

#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
        int ans = 0;
        int i = 0; int j = height.size()-1;
        while(i<j) {
           
            int area = min(height[i] , height[j]) * (j-i);
            
            ans = max(ans , area);
            if(height[i] <= height[j]) i++;
            else j--;
        }
        return ans;
    }

// Intuition : Here the main catch is when to increment i and when to decrement j.
// Simply, we do i++ when nums[j] >= nums[i] else we do j--;
// By this manner we solve the problem.