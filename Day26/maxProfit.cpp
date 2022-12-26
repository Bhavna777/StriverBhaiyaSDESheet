// Problem Link :- https://www.codingninjas.com/codestudio/problems/job-sequencing-problem_1169460


#include <bits/stdc++.h> 

bool static comparison(vector<int> a , vector<int> b) {
    return (a[1] > b[1]);
}
int jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size();

    sort(jobs.begin(),jobs.end(), comparison);

    int maxi = jobs[0][0];

    for (int i=1; i<n; i++){
        maxi = max(maxi, jobs[i][0]);
    }
    
    int temp[maxi + 1];

    for(int i=0; i<=maxi; i++){
        temp[i] = -1;    
    }
    
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i][0]; j > 0; j--) {
            if (temp[j] == -1) {
                temp[j] = i;
                ans += jobs[i][1];
                break;
            }
        }
    }

    return ans;
}