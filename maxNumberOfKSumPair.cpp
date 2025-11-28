// Question : You are given an integer array nums and an integer k.
// In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.
// Return the maximum number of operations you can perform on the array.

#include <bits/stdc++.h>
using namespace std;

 //  first approach
//     int maxOperations(vector<int>& nums, int k) {
//         int ans = 0;
//         map<int , int> mp;
//         for(auto it : nums) mp[it]++;

//         for(int i = 0; i< nums.size(); i++) {
//             int v = k - nums[i];
//             auto at = mp.find(nums[i]);
//             if (at == mp.end()) continue; 
//             if (at != mp.end()) {
//                 at->second--;
//                 if (at->second == 0) mp.erase(at);
//             }

//             // Check partner exists
//             auto it = mp.find(v);
//             if (it != mp.end()) {
//                 ans++;
//                 it->second--;
//                 if (it->second == 0) mp.erase(it);
//             }
//         }
//         return ans;
//     }


//  second approach
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());    // O(n log n)
        int l = 0, r = (int)nums.size() - 1;
        int ans = 0;

        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum == k) {
                ans++;
                l++; r--;                // use both elements, move both pointers
            } else if (sum < k) {
                l++;                    // need bigger sum
            } else {
                r--;                    // need smaller sum
            }
        }
        return ans;
    }