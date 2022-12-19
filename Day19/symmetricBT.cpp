// Problem Link :- https://leetcode.com/problems/symmetric-tree/


class Solution {
public:

    bool solve(TreeNode * root1, TreeNode * root2) {
        if (root1 == NULL || root2 == NULL){
            return root1 == root2;
        }

        return (root1 -> val == root2 -> val) && solve(root1 -> left, root2->
        right) && solve(root1 -> right, root2 -> left);
    }


    bool isSymmetric(TreeNode* root) {
        if (root == NULL){
            return true;
        }
        return solve(root -> left, root -> right);
    }
};