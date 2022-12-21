// Problem Link :- https://leetcode.com/problems/binary-search-tree-iterator/


class BSTIterator {
public:
    stack<TreeNode*>s;
    
    void solve(stack<TreeNode*>& s, TreeNode* root){
        if(!root) return;
        s.push(root);
        solve(s, root->left);
    }

    BSTIterator(TreeNode* root) {
        solve(s, root);
    }
    
    int next() {
        TreeNode* node = s.top();
        s.pop();
        if(node->right){
            solve(s, node->right);
        } 
        return node->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};