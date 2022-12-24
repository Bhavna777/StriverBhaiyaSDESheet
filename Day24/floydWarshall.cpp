// Problem Link :- https://www.codingninjas.com/codestudio/problems/2041979


int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<vector<int>>adj(n, vector<int>(n,0));
    for(auto& it:edges){
        int u = it[0]-1;
        int v = it[1]-1;
        int w = it[2];
        adj[u][v] = w;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(adj[i][j] == 0 && i != j){
                adj[i][j] = INT_MAX;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(adj[j][i]==INT_MAX || adj[i][k]==INT_MAX || adj[j][i] + adj[i][k]==INT_MAX)
                    continue;
                adj[j][k] = min(adj[j][k], adj[j][i] + adj[i][k]);
            }
        }
    }
    
    if(adj[src-1][dest-1] == INT_MAX){
        return 1e9;
    }else{
        return adj[src-1][dest-1];
    }
}