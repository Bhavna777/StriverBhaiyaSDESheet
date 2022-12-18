// Problem Link :- https://leetcode.com/problems/maximum-depth-of-binary-tree/ 


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        int leftHeight = maxDepth(root -> left);
        int rightHeight = maxDepth(root -> right);

        int ans = 1 + max(leftHeight, rightHeight);

        return ans;
    }
};