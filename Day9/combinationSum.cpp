// Problem Link :- https://leetcode.com/problems/combination-sum/ 



void combination(vector<int>& candidates, int index, int target, vector<int>& temp, vector<vector<int>>& ans){
    int n = candidates.size();
    if (index == n) {
        if (target == 0) {
            ans.push_back(temp);
        }
        return;
    }

    if (candidates[index] <= target) {
        temp.push_back(candidates[index]);
        combination( candidates, index, target - candidates[index], temp, ans);
        temp.pop_back();
    }

    combination(candidates, index + 1, target, temp, ans);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>>ans;
    vector<int>temp;
    combination(candidates, 0, target, temp, ans);
    return ans;
}