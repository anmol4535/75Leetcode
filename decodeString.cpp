// Question : Given an encoded string, return its decoded string.
// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
// You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].
// The test cases are generated so that the length of the output will never exceed 105.

#include <bits/stdc++.h>
using namespace std;

 string decodeString(string s) {
    stack<int> counts;
    stack<string> strs;
    string current;
    int num = 0;

    for (char c : s) {
        if (isdigit(c)) {
            // parse multi-digit number
            num = num * 10 + (c - '0');
        } else if (c == '[') {
            // push the number and the current built string
            counts.push(num);
            strs.push(current);
            // reset for new segment
            num = 0;
            current.clear();
        } else if (c == ']') {
            // pop count and previous string, then append current repeated count times
            int k = counts.empty() ? 1 : counts.top(); counts.pop();
            string prev = strs.empty() ? string() : strs.top(); if (!strs.empty()) strs.pop();

            // repeat current k times (total output size is guaranteed <= 1e5)
            string repeated;
            for (int i = 0; i < k; ++i) repeated += current;

            cout<<" Here is Prev: "<< prev<<endl;
            // new current becomes prev + repeated
            current = prev + repeated;
        } else {
            // normal character
            current.push_back(c);
        }
    }
    return current;

    }