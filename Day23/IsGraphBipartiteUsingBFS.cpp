// Problem Link :- https://leetcode.com/problems/is-graph-bipartite/


class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,0);

        for(int i=0;i<n;i++){
            if(!color[i]){
                queue<int>q;
                q.push(i);
                color[i] = 1;

                while(!q.empty()){
                    int curr = q.front();
                    q.pop();

                    for(int j=0; j<graph[curr].size(); j++){
                        if(color[graph[curr][j]] == 0){
                            color[graph[curr][j]] =- color[curr];
                            q.push(graph[curr][j]);
                        }else if(color[graph[curr][j]] !=- color[curr]){
                            return false;
                        }
                    }
                    
                }

            }
        }
        return true;
    }
};