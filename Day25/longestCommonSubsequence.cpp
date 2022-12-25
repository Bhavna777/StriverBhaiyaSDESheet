// Problem Link :- https://leetcode.com/problems/longest-common-subsequence/


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> ans(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i{1}; i <= text1.size(); i++) {
            for (int j{1}; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    ans[i][j] = ans[i - 1][j - 1] + 1;
                } else {
                    ans[i][j] = max(ans[i - 1][j], ans[i][j - 1]);
                }
            }
        }
        return ans.back().back(); 
    }
};