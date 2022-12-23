// Problem Link :- https://leetcode.com/problems/course-schedule/


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        vector<int>depth(numCourses, 0);
        for(auto m: prerequisites){
            graph[m[1]].push_back(m[0]);
            depth[m[0]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(depth[i] == 0)
                q.push(i);
        }

        int count = 0;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            count++;
            for(int i = 0; i < graph[course].size(); i++){
                if(--depth[graph[course][i]] == 0)
                    q.push(graph[course][i]);
            }
        }
        return count == numCourses;
    }
};