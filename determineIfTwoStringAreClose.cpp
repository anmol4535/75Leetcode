// Question : Two strings are considered close if you can attain one from the other using the following operations:
// Operation 1: Swap any two existing characters.
// For example, abcde -> aecdb
// Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
// For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
// You can use the operations on either string as many times as necessary.
// Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

#include <bits/stdc++.h>
using namespace std;

bool closeStrings(string word1, string word2) {
        vector<int> freq1(26 , 0) , freq2(26,0);
        if(word1.size() != word2.size()) return false;

        for(int i = 0; i< word1.size() ; i++) {
            int ch = word1[i] - 'a';
            freq1[ch]++;
        }
        for(int i = 0; i< word2.size() ; i++) {
            int ch = word2[i] - 'a';
            freq2[ch]++;
        }

        for(int i  = 0; i< 26; i++){
            if((freq1[i] == 0 && freq2[i]!=0) || (freq1[i] != 0 && freq2[i]==0)) return false;
        }

        sort(freq1.begin() , freq1.end());
        sort(freq2.begin() , freq2.end());

        for(int i = 0; i< freq1.size();i++) {
            if(freq1[i] != freq2[i]) return false;
        }
        return true;

        return false;
    }

// this question have a tricky parts and here you have to match the same frequency of different elements.
// you don't have to match the char with there freq but the main point is how to chaeck every false condition in question. 