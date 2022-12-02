// Problem Link :- https://leetcode.com/problems/merge-intervals/ 

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector < vector < int >> ans;
    int n = intervals.size();

    for (int i = 0; i < n; i++) {
    if (ans.empty() || ans.back()[1] < intervals[i][0]) {
        vector < int > v = {
        intervals[i][0],
        intervals[i][1]
        };

        ans.push_back(v);
    } else {
        ans.back()[1] = max(ans.back()[1], intervals[i][1]);
    }
    }

    return ans;
}