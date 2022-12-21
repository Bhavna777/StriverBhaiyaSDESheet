// Problem LInk :- https://leetcode.com/problems/kth-smallest-element-in-a-bst/


class Solution {
public:

    int solve(TreeNode* root, int k, int& ans){
       if(root == NULL){
           return 0;
       } 

       int left = solve(root->left, k, ans) + 1;
       int right = solve(root->right, k - left, ans) + 1;
       
       if(k == left){
           ans = root->val;
       } 
       return left + right - 1;
    }


    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        solve(root, k, ans);
        return ans;
    }
};