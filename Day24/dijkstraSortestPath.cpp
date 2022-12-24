// Problem Link :- https://www.codingninjas.com/codestudio/problems/920469


#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    queue<int>q;
    vector<int>ans(vertices, INT_MAX);
    ans[source] = 0;
    q.push(source);
    
    vector<pair<int, int>>adj[vertices];
    for(int i = 0; i < edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(auto &i : adj[top]){
            if(ans[top] + i.second < ans[i.first]){
                ans[i.first] = ans[top] + i.second;
                q.push(i.first);
            }
        }
    }
    return ans;
}
