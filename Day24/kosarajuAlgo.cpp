// Problem Link :- https://www.codingninjas.com/codestudio/problems/985311


#include<bits/stdc++.h>

void topo(int i, vector<bool>&vis, stack<int>&s, unordered_map<int,list<int>>& adj){
    vis[i]=1;

    for(auto it : adj[i]){
        if(!vis[it]){
            topo(it, vis, s, adj);
        }
    }
    
    s.push(i);
}

void dfs(int node, vector<bool>&vis, vector<int>&temp, unordered_map<int,list<int>>&trans){
    vis[node]=1;
    temp.push_back(node);

    for(auto it:trans[node]){
        if(!vis[it]){
            dfs(it, vis, temp, trans);
        }
    }
}


vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    unordered_map<int,list<int>>adj;
    unordered_map<int,list<int>>trans;
    int m = edges.size();

    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        trans[v].push_back(u); 
    }
    
    stack<int> s;
    vector<bool>vis(n,0);
    
    for(int i=0; i<n; i++){
        if(!vis[i]){
            topo(i, vis, s, adj);
        }
    }
    
    fill(vis.begin(), vis.end(), 0);
    
    
    vector<vector<int>>ans;
    
    while(!s.empty()){
        vector<int>temp;
        int node = s.top();
        s.pop();
        if(!vis[node]){
            dfs(node, vis, temp, trans);
        }
        
        ans.push_back(temp);
    }
    
    return ans;
}