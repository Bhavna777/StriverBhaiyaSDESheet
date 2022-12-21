// Problem Link :- https://leetcode.com/problems/two-sum-iv-input-is-a-bst/ 


class Solution {
public:

    void inorder(TreeNode* root, vector<int>&arr){
        if(root == NULL){
            return ;
        }
        inorder(root -> left, arr);
        arr.push_back(root -> val);
        inorder(root -> right, arr);
    }

    bool findTargetInSortedArr(vector<int>&arr, int k){
        int start = 0;
        int end = arr.size() - 1;
        while(start < end){
            if(k == arr[start] + arr[end]){
                return true;
            }else if(k < arr[start] + arr[end]){
                end--;
            }else{
                start++;
            }
        }

        return false;
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int>arr;
        inorder(root, arr);
        return findTargetInSortedArr(arr, k);
    }
};