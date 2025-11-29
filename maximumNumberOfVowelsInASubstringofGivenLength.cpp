// Question : Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
//Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.


#include <bits/stdc++.h>
using namespace std;

 bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false; 
    }
    int maxVowels(string s, int k) {
        int i = 0,j = 0;
        int maxVol = 0;
        int v = 0;

        for(; j<s.size() ; j++){
            if(isVowel(s[j])) v++;

            while(k< (j-i+1)) {
                if(isVowel(s[i])) v--;
                i++;
            }

            maxVol = max(maxVol , v);
        }
        return maxVol;
    }


    // Always remember the khandani templete of sliding window technique.
//This is simple but very curial and logic testing question of sliding window.