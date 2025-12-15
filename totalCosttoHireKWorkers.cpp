// Question : You are given a 0-indexed integer array costs where costs[i] is the cost of hiring the ith worker.
// You are also given two integers k and candidates. We want to hire exactly k workers according to the following rules:
// You will run k sessions and hire exactly one worker in each session.
// In each hiring session, choose the worker with the lowest cost from either the first candidates workers or the last candidates workers. Break the tie by the smallest index.
// For example, if costs = [3,2,7,7,1,2] and candidates = 2, then in the first hiring session, we will choose the 4th worker because they have the lowest cost [3,2,7,7,1,2].
// In the second hiring session, we will choose 1st worker because they have the same lowest cost as 4th worker but they have the smallest index [3,2,7,7,2]. Please note that the indexing may be changed in the process.
// If there are fewer than candidates workers remaining, choose the worker with the lowest cost among them. Break the tie by the smallest index.
// A worker can only be chosen once.
// Return the total cost to hire exactly k workers.

#include <bits/stdc++.h>
using namespace std;

long long totalCost(vector<int>& costs, int k, int candidates) {

        int n = costs.size();
        long long sum = 0;

        priority_queue<int, vector<int>, greater<int>> left, right;

        int i = 0, j = n - 1;

        // Fill left heap
        for(int cnt = 0; cnt < candidates && i <= j; cnt++) {
            left.push(costs[i++]);
        }

        // Fill right heap
        for(int cnt = 0; cnt < candidates && i <= j; cnt++) {
            right.push(costs[j--]);
        }

        // Hire k workers
        while(k--) {

            int l = left.empty()  ? INT_MAX : left.top();
            int r = right.empty() ? INT_MAX : right.top();

            if(l <= r) {
                sum += l;
                left.pop();
                if(i <= j) left.push(costs[i++]);
            }
            else {
                sum += r;
                right.pop();
                if(i <= j) right.push(costs[j--]);
            }
        }

        return sum;
    }