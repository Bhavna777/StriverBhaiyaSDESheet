// Problem Link :- https://leetcode.com/problems/validate-binary-search-tree/ 


class Solution {
public:

    bool isValid(TreeNode* root, TreeNode* &pre){
        if(root == NULL){
            return true;
        } 

        if(!isValid(root->left, pre)){
            return false;  
        } 

        if(pre && root->val <= pre->val){
            return false;
        } 

        pre = root;

        return isValid(root->right, pre);
    }


    bool isValidBST(TreeNode* root) {
        TreeNode* pre = NULL;
        return isValid(root, pre);
    }
};