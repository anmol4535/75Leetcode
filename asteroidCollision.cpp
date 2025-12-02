// Question : We are given an array asteroids of integers representing asteroids in a row. The indices of the asteroid in the array represent their relative position in space.
// For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
// Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
        // vector<int> vec;
        // stack<int> st;

        // for(int i = 0; i< asteroids.size() ; i++){
        //     if(st.empty() || ((asteroids[i] > 0 && st.top() > 0) || ( asteroids[i] < 0 && st.top() < 0) )) {
        //         st.push(asteroids[i]);
        //     }else{
        //         if(asteroids[i] > 0 && st.top() <0){
        //            st.push(asteroids[i]);
        //         }
        //         if(asteroids[i] < 0 && st.top() > 0) {
        //             while(!st.empty() && (st.top() > 0 && st.top() <= abs(asteroids[i]))) {   
        //                if(st.top() == abs(asteroids[i])){
        //                 st.pop();
        //                 break;
        //                } 
        //                 st.pop();
        //                 if(st.empty() || st.top() < 0 ) st.push(asteroids[i]);
        //             }  
                    
        //         }
        //     }
        // }

        // while(!st.empty()){
        //     vec.push_back(st.top());
        //     st.pop();
        // }
        // reverse(vec.begin() , vec.end());
        // return vec;

        // another approach 
        vector<int> st; // use vector as a stack (faster & simpler than std::stack for this)

    for (int a : asteroids) {
        bool alive = true;

        // collisions only happen when current a is moving left (a < 0)
        // and stack top is moving right (st.back() > 0)
        while (alive && a < 0 && !st.empty() && st.back() > 0) {
            int top = st.back();

            if (abs(a) > top) {
                // top explodes, keep checking with the next asteroid on stack
                st.pop_back();
                continue;
            } else if (abs(a) == top) {
                // both explode
                st.pop_back();
                alive = false; // current also dies
                break;
            } else {
                // top is larger, current explodes
                alive = false;
                break;
            }
        }

        if (alive) st.push_back(a);
    }

    return st;
    }