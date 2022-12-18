// Problem Link :- https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/ 


class Solution {
public:

    void dfs(TreeNode* root, int level, vector<vector<int>> & ans) {
        if (root == NULL){
            return ;
        }
            
        if (ans.size() == level) {
            vector<int> temp;
            ans.push_back(temp);
        }
        if (level % 2 == 0)   
            ans[level].push_back(root -> val);
        else{
            ans[level].insert(ans[level].begin(), root -> val);   
        }
        
        dfs(root -> left, level + 1, ans);  
        dfs(root -> right, level  +1, ans);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root, 0, ans);
        return ans;
    }
};