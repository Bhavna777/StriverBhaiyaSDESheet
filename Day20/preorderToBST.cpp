// Problem Link :- https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/ 


class Solution {
public:
    int i = 0;
    TreeNode* bstFromPreorder(vector<int>& preorder, int range = INT_MAX) {
        int n = preorder.size();
        if(i == n || preorder[i] > range){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[i++]);

        root->left = bstFromPreorder(preorder, root->val);
        root->right = bstFromPreorder(preorder, range);


        return root;
    }
};