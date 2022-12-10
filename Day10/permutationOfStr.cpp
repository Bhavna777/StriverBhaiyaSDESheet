// Problem Link :- https://leetcode.com/problems/permutations 



void permutation(vector<int>& nums, int index, vector<vector<int>>& ans){
    int n = nums.size();
    if (index == n) {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < n; i++) {
        swap(nums[index], nums[i]);
        permutation(nums, index+1, ans);
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>>ans;

    permutation(nums, 0, ans);

    return ans;
}