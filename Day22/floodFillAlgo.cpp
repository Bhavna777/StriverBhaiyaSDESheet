// Problem Link :- https://leetcode.com/problems/flood-fill/


class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        
        if (oldColor == color) {
            return image;
        }
        
        queue<pair<int, int>>q;
        
        q.push({sr, sc});
        
        int n = image.size();
        int m = image[0].size();
        
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            
            q.pop();
            
            if (image[i][j] == oldColor) {
                image[i][j] = color;
                
                if (i != 0) {
                     q.push({i-1, j});
                }
                
                if (i != n-1) {
                     q.push({i+1, j});
                }
            
                if (j != 0) {
                     q.push({i, j-1});
                }
                
                if (j != m-1) {
                     q.push({i, j+1});
                }
            } 
        }
        
        return image;
    }
};