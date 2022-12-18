// Problem Link :- https://leetcode.com/problems/diameter-of-binary-tree/ 



class Solution {
public:

    int height(TreeNode* root, int& d) {
        if(root == NULL){
            return 0;
        }

        int leftHeight = height(root -> left, d);
        int rightHeight = height(root -> right, d);

        d = max(d, leftHeight + rightHeight);

        int ans = 1 + max(leftHeight, rightHeight);

        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        height(root, d);
        return d;
    }
};