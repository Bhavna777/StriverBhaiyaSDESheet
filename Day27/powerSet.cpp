// Problem Link :- https://www.codingninjas.com/codestudio/problems/1062667


#include <bits/stdc++.h> 
vector<vector<int>> pwset(vector<int>v)
{
    vector<vector<int>> ans;
    int n = v.size();
     
    for(int i=0; i<(1<<n); i++){
        vector<int>subset;
        for(int j=0; j<n; j++){
            if(i & (1<<j)){
                subset.push_back(v[j]);
            }
        }
        ans.push_back(subset);
    }
    
    return ans;
}