// problem Link :- https://www.codingninjas.com/codestudio/problems/1095633

#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
   unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0; i<g.size(); i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    vector<int> key(n+1);
    vector<bool>isMST(n+1);
    vector<int> parent(n+1);
    
    for(int i=0;i<=n;i++){
        key[i] = INT_MAX;
        parent[i] = -1;
        isMST[i] = false;
    }
    
    key[1] = 0;
    parent[1] = -1;
    
    for(int i=1; i<=n; i++){
        int mini = INT_MAX;
        int u;
        for(int v=1; v<=n; v++){
            if(isMST[v] == false && key[v] < mini){
                u = v;
                mini = key[v];
            }
        }
        isMST[u] = true;
        for(auto neighbour: adj[u]){
            int v = neighbour.first;
            int w = neighbour.second;
            if(isMST[v] == false && w < key[v]){
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    
    vector<pair<pair<int, int>, int>>ans;
    for(int i=2;i<=n;i++){
        ans.push_back({{parent[i],i},key[i]});
    }
    
    return ans;
}
