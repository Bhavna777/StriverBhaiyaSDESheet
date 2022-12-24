// Problem Link :- https://www.codingninjas.com/codestudio/problems/2041977


#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
   vector<int> distance(n+1, 1e9);
   distance[src] = 0;
   for(int i=1; i<n; i++){
       for(auto it:edges){
           int u = it[0];
           int v = it[1];
           int w = it[2];

           if(distance[u] + w < distance[v] && distance[u] != distance[v]){
               distance[v] = distance[u] + w;
           }
       }
   }
   return distance[dest];
}