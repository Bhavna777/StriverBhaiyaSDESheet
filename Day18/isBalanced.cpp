// Problem Link :- https://leetcode.com/problems/balanced-binary-tree/ 


class Solution {
public:

    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int leftHeight = height(root -> left);

        if (leftHeight == -1){
            return -1;
        }

        int rightHeight = height(root -> right);

        if(rightHeight == -1){
            return -1;
        }   

        if (abs(leftHeight - rightHeight) > 1){
            return -1;
        } 

        return max (leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {

        if(height(root) != -1){
            return true;
        }else{
            return false;
        }

    }
};