// Problem Link :- https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/ 


class Solution {
public:

    TreeNode* solve(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie, unordered_map<int, int>& mp) {
        if(ps > pe) return NULL;
        TreeNode* root = new TreeNode(preorder[ps]);
        int i = mp[preorder[ps]];
        root->left = solve(preorder, ps + 1, ps + i - is, inorder, is, i - 1, mp);
        root->right = solve(preorder, ps + i - is + 1, pe, inorder, i + 1, ie, mp);
        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int>mp;
        int n = inorder.size();
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        } 
        int m = preorder.size();
        return solve(preorder, 0, m - 1, inorder, 0, n - 1, mp);
    }
};