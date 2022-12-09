// Problem Link :- https://leetcode.com/problems/combination-sum-ii 


void combination(vector<int>& candidates, int index, int target, vector<int>& temp, vector<vector<int>>& ans){
    int n = candidates.size();
    if (target == 0) {
        ans.push_back(temp);
        return;
    }

    for (int i=index; i<n; i++){
        if (i > index && candidates[i] == candidates[i-1]){
            continue;
        } 
        if(candidates[i] > target){
            break;
        } 


        temp.push_back(candidates[i]);
        combination(candidates, i+1, target - candidates[i], temp, ans);
        temp.pop_back();
    }

}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>>ans;
    vector<int>temp;
    sort(candidates.begin(), candidates.end());
    combination(candidates, 0, target, temp, ans);
    return ans;
}