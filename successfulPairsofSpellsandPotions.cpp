// Question : You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.
// You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.
// Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.

#include <bits/stdc++.h>
using namespace std;

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin() , potions.end());
        vector<int> ans;

        for(int k = 0; k< spells.size() ; k++){
            int a = 0;
            int i = 0; int j = potions.size() -1;
            while(i<= j){
                int mid =  (i+j)/2;
                long long pro = (long long)spells[k]*(long long)potions[mid];
                if(pro >= success){
                    a = potions.size()-mid;
                    j = mid -1;
                   
                }else i = mid+1;
            }
        
            ans.push_back(a);
        }
        return ans;
    }

    