// Problem Link :- https://leetcode.com/problems/is-graph-bipartite/


class Solution {
public:
    int flag = true;
    void dfs(vector<vector<int>>& graph, int i, int col,vector<int>& color){
		if(color[i]){
			if(col!=color[i]){
				flag = false;
			}
			return;
		}
		color[i]=col;
		for(auto x:graph[i]){
			dfs(graph, x, 3-col, color);
		}
	}

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
		vector<int>color(n,0);
		for(int i=0; i<graph.size(); i++){
			if(color[i]==0){
				dfs(graph, i, 1, color);
			}
		}
		return flag;
    }
};