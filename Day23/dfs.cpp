// Problem Link :- https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    void dfs(vector<int>adj[], int node, vector<int>&temp, vector<int>&ans){
        ans.push_back(node); 
        temp[node] = 1; 
        for(auto it : adj[node]) {
            if(!temp[it]) {
                dfs(adj, it, temp, ans); 
            }
        }
    }
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans; 
	    vector<int>temp(V+1, 0); 
        for(int i = 0;i<V;i++) {
            if(!temp[i]){
                dfs(adj, i, temp, ans); 
            }
        }
	    return ans; 
    }
};