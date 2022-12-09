// Problem Link :- https://leetcode.com/problems/subsets-ii/ 


void subsets(vector<int>& nums, int index, vector<int>& dupSum, vector<vector<int>>& ans){
    ans.push_back(dupSum);
    int n = nums.size();

    for(int i=index; i<n; i++){
        if(i != index && nums[i] == nums[i-1]){
            continue;
        }

        dupSum.push_back(nums[i]);
        subsets(nums, i + 1, dupSum, ans);
        dupSum.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int>dupSum;
    sort(nums.begin(), nums.end());
    subsets(nums, 0, dupSum, ans);
    return ans;
}