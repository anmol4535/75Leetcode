// Question : Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

#include <bits/stdc++.h>
using namespace std;

// this is my code which i code initial .
int longestOnes(vector<int>& nums, int k) {
        int ones= 0;
        int maxi = INT_MIN;
        int zeroes = 0;
        int i = 0, j = 0;

        for(auto it : nums) if(it == 0) zeroes++;
        if(zeroes <= k) return nums.size();
        zeroes= 0;

        while( j< nums.size()) {
            if(zeroes > k) {
                while(zeroes > k) {
                    if(nums[i] == 1) {
                        ones--;
                       // cout<< ones;
                    }
                    else zeroes--;
                    i++;
                }
            }
                if(nums[j]) {
                    ones++;
                    cout<< j<< " "<< ones<<endl;
                }
                if(nums[j] == 0) zeroes++;
                j++;
                maxi = max(maxi , ones);
             //   cout<< ones<<" "<<zeroes<<endl;
        }
        return maxi+k;
    }

// this is code which i learn from chatgpt , it is clean and clear code
int longestOnes(vector<int>& nums, int k) {
       int n = nums.size();
        int i = 0;            // left pointer
        int zeros = 0;        // number of zeros in current window
        int maxlen = 0;       // best window length found

        for (int j = 0; j < n; j++) {
            if (nums[j] == 0) zeros++;

            // If we used more than k flips, move left pointer until zeros <= k
            while (zeros > k) {
                if (nums[i] == 0) zeros--;
                i++;
            }

            // Window [i..j] is valid (zeros <= k)
            maxlen = max(maxlen, j - i + 1);
        }

        return maxlen;
    }


// From this question i have learn to write a clean and simple code that would be understandable.
