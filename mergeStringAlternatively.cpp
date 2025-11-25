#include <bits/stdc++.h>
using namespace std;

    string mergeAlternately(string word1, string word2) {
        int i = 0; int j = 0;
        string str;
        int n1 = word1.size();
        int n2 = word2.size();

        while(i<n1 && j< n2){
            str+= word1[i];
            i++;
            str+= word2[j];
            j++;
        }

        while(i< n1){
            str+= word1[i];
            i++;
        }
        while(j < n2){
            str+= word2[j];
            j++;
        }
        return str;
    }
