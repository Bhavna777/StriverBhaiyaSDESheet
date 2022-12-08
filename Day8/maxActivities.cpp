// Problem Link :- codingninjas.com/codestudio/problems/1062712 



#include<bits/stdc++.h>

int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n = start.size();
    vector<pair<int, int>> activity(n);

    for (int i = 0; i < n; i++) {
        activity[i].first = finish[i];
        activity[i].second = start[i];
    }
    
    sort(activity.begin(), activity.end());

    int ans = 1;
    int currTime = activity[0].first;

    for (int i = 1; i < n; i++) {
        if (activity[i].second >= currTime) {
            ans++;
            currTime = activity[i].first;
        }
    }
    return ans;
}