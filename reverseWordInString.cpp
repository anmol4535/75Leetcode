// Question : Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
        vector<string> vec;
        string str = "";
        for(int i = 0; i< s.size(); i++){
            if(s[i] == ' '){
                if(str.size()!=0)
                    vec.push_back(str);
                str ="";
            }else{
                str+= s[i];
            }
        }
        if(str.size()!= 0)
            vec.push_back(str);
        str="";

        reverse(vec.begin() , vec.end());
        for(int i = 0; i< vec.size() ; i++){
            str+=vec[i];
            if(i< vec.size()-1){
                str+=' ';
            }
        }
        return str;
    }