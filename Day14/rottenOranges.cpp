// Problem Link :- https://leetcode.com/problems/rotting-oranges/ 


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()){
            return 0;
        } 

        int m = grid.size();
        int n = grid[0].size();
        int d = 0;
        int total = 0;
        int count = 0;

        queue<pair<int, int>>q;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] != 0){
                    total++;
                }

                if(grid[i][j] == 2){
                    q.push({i, j});
                } 
            }
        }
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!q.empty()){
            int k = q.size();
            count = count + k; 
            while(k--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1){
                        continue;
                    } 

                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
            if(!q.empty()){
                d++;
            } 
        }
        
        if(total == count){
            return d;
        }

        return -1;
    }
};