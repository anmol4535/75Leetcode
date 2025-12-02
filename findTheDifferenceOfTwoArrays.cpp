// Question: Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:
// answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
// answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
// Note that the integers in the lists may be returned in any order.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;

        vector<int > vec;
        set<int> st;
        for(int i = 0; i< nums1.size() ; i++){
            bool flag = true;
            for(int j = 0 ; j< nums2.size() ; j++){
                if(nums1[i] == nums2[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag && !st.count(nums1[i])) {
                vec.push_back(nums1[i]);
                st.insert(nums1[i]);
            }
        }

        ans.push_back(vec);

        vec.clear();
        st.clear();

        for(int i = 0; i< nums2.size() ; i++){
            bool flag = true;
            for(int j = 0 ; j< nums1.size() ; j++){
                if(nums2[i] == nums1[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag && !st.count(nums2[i])) {
                vec.push_back(nums2[i]);
                st.insert(nums2[i]);
            }
        }
        ans.push_back(vec);
        return ans;
    }