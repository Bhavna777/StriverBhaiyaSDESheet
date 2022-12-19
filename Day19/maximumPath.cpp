// Problem Link :- https://leetcode.com/problems/binary-tree-maximum-path-sum/ 


class Solution {
public:

    int solve(TreeNode* root, int& maxSum){
        if(!root){
            return 0;
        } 
        int left = max(0, solve(root->left, maxSum));
        int right = max(0, solve(root->right, maxSum));
        maxSum = max(maxSum, left + right + root->val);
        return max(left, right) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        solve(root, maxSum);
        return maxSum;
    }
};