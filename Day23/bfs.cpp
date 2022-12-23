// Problem Link :- https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1 


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector < int >ans;
        vector < int >temp(V, 0);
        queue < int > q;
        q.push(0);
        temp[0] = 1;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for (auto it: adj[node]) {
                if (!temp[it]) {
                    q.push(it);
                    temp[it] = 1;
                }
            }
        }
        
        return ans;
    }
};