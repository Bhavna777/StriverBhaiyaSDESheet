// Problem Link :- https://leetcode.com/problems/binary-tree-level-order-traversal/ 


class Solution {
public:

    void dfs(vector<vector<int>>& ans, TreeNode* root, int level){
        if(root == NULL){
            return ;
        } 

        if(level == ans.size()){
            ans.push_back(vector<int>());
        }
         
        ans[level].push_back(root->val);
        dfs(ans, root->left, level + 1);
        dfs(ans, root->right, level + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        dfs(ans, root, 0);
        return ans;
    }
};