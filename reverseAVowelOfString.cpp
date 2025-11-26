// Queations: Given a string s, reverse only all the vowels in the string and return it.

// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.4

#include <bits/stdc++.h>
using namespace std;

bool isVowel(char ch) {
        if(ch =='A' || ch =='E'||ch =='I'||ch =='O' ||ch =='U'||ch =='a'||ch =='e'
        ||ch =='o'||ch =='i'||ch =='u') return true;
        return false;
    }
    string reverseVowels(string s) {
        int i = 0; int j = s.size()-1;
        while(i<j){
            while(!isVowel(s[i])&& i<j) i++;
            while(!isVowel(s[j]) && i<j) j--;

            swap(s[i] ,s[j]);
            i++;
            j--;
         }
        return s;
    }