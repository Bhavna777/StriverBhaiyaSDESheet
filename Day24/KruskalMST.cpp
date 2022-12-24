// Problem Link :- https://www.codingninjas.com/codestudio/problems/1082553


#include<bits/stdc++.h>

int findPar(int u,vector<int> &parant){
    if(u == parant[u]){
        return u;
    }
    return parant[u] = findPar(parant[u],parant);
}
    
int findUnion(int u, int v, vector<int> &rank,vector<int> &parant){
    if(rank[u]<rank[v]){
        parant[u] = v;
    }else if(rank[v]<rank[u]){
        parant[v] = u;
    }else{
        parant[v] = u;
        rank[u]++;
    }
}
    
bool compair(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
} 
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
    sort(graph.begin(),graph.end(),compair);
    int ans = 0;
    vector<int>parant(n+1);
    vector<int>rank(n+1,0);
    
    for(int i=1; i<parant.size(); i++){
        parant[i] = i;
    } 
    
    for(auto i:graph){
        if(findPar(i[0],parant)!=findPar(i[1],parant)){
            ans = ans + i[2];
            findUnion(findPar(i[0],parant),findPar(i[1],parant),rank,parant);
        }
    }
    
    return ans;
}