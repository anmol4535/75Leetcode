// Question : Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.


#include <bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> mp;
        set<int> st;
        for(auto it : arr) mp[it]++;

        for(auto it : mp){
            int v = it.second;
            if(st.count(v)) return false;
            else{
                st.insert(v);
            } 
        }
        return true;
}