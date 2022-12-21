// Problem Link :- https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/


class Solution {
public:

    pair<int,pair<int,int>> solve(TreeNode* node, int & ans){
        if(node == NULL){
            return {0,{INT_MAX,INT_MIN}};
        } 
        auto left = solve(node->left,ans);
        auto right = solve(node->right,ans);

        if(right.second.first<=node->val || left.second.second>= node->val){
            return {0,{INT_MIN,INT_MAX}};
        }
        int num = left.first + right.first + node->val;
        ans = max(ans,num);
        int miniVal = min(node->val,left.second.first);
        int maxVal = max(node->val,right.second.second);
        return {num,{miniVal, maxVal}};
    }

    int maxSumBST(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans;
    }
};