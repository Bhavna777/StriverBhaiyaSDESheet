// Problem Link :- https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/ 


class Solution {
public:

    TreeNode* solve(int start, int end, vector<int>& nums){
        if(start > end){
            return NULL;
        }
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = solve(start, mid - 1, nums);
        root->right = solve(mid + 1, end, nums);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(0, nums.size() - 1, nums);
    }
};