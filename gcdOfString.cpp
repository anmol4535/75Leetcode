#include <bits/stdc++.h>
using namespace std;

string gcdOfStrings(string str1, string str2) {
        // neglecting the wrong testcase
        if(str1+str2 != str2+str1) return "";

        int n1 = str1.size();
        int n2 = str2.size();
        int val = 0;
        
        for(int i = 1;i<= min(n2,n1); i++) {
            if(n1%i ==0 && n2%i==0) {
                val = i;
                cout<< i<<endl;
            }
        }

        string str = str1.substr(0,val);
        return str;
}
