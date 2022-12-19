// Problem Link :- https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/ 


class Solution {
public:

    TreeNode* solve(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe, unordered_map<int, int>& mp) {
        if(is > ie) return nullptr;
        
        int val = postorder[pe];
        TreeNode *root = new TreeNode(val);
        if(is == ie) return root;
        
        int iroot = mp[val];
        int nleft = iroot - is;
        root->right = solve(inorder, iroot + 1, ie, postorder, ps + nleft, pe - 1, mp);
        root->left = solve(inorder, is, iroot - 1, postorder, ps, ps + nleft - 1, mp);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size(), i = 0;
        unordered_map<int, int>mp;

        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }
        
        return solve(inorder, 0, n - 1, postorder, 0, n - 1, mp);
    }
};