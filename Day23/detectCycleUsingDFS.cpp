// Problem Link :- https://leetcode.com/problems/course-schedule/


class Solution {
public:

    bool checkcycle(vector<vector<int>> &graph,int u,int vis[],int path[]){
        vis[u]=1;
        path[u]=1;
        for(auto m: graph[u]){
            if(path[m]){
                return true;
            }
            if(!vis[m] && checkcycle(graph,m,vis,path)){
                return true;
            }
        }
        path[u]=0;
        return false;
        
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto m: prerequisites)
        {
            graph[m[1]].push_back(m[0]);
        }
        int vis[numCourses];
        int path[numCourses];
        
        for(int i=0; i<numCourses; i++){
            vis[i]=0;
            path[i]=0;
        } 
        for(int i=0;i<numCourses;i++){
            if(!vis[i] && checkcycle(graph,i,vis,path)){
                return false;
            } 
        }
            
        return true;
    }
};