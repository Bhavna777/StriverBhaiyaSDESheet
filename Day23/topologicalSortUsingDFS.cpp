// Problem Link :- https://practice.geeksforgeeks.org/problems/topological-sort/1


class Solution
{
	public:
	
	void solve(vector < int > adj[], int node, vector < int > & vis, stack < int > & st) {
        vis[node] = 1;
    
        for (auto it: adj[node]) {
          if (!vis[it]) {
            solve(adj, it, vis, st);
          }
        }
        st.push(node);
    }
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack < int > st;
        vector < int > vis(V, 0);
        
        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {
                solve(adj, i, vis, st);
            }
        }
        
        vector < int > ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
	}
};