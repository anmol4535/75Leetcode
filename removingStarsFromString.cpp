// Question : You are given a string s, which contains stars *.
// In one operation, you can:
// Choose a star in s.
// Remove the closest non-star character to its left, as well as remove the star itself.
// Return the string after all stars have been removed.
// Note:
// The input will be generated such that the operation is always possible.
// It can be shown that the resulting string will always be unique.

#include <bits/stdc++.h>
using namespace std;

 string removeStars(string s) {
        string str;
        stack<char> st;

        for(int i = 0; i< s.size() ; i++){
            if(s[i] != '*'){
                st.push(s[i]);
            }else{
                st.pop();
            }
        }
        while(!st.empty()){
            str+= st.top();
            st.pop();
        }
        reverse(str.begin() , str.end());

        return str;
    }