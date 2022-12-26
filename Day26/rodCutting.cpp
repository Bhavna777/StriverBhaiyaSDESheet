// Problem Link :- https://leetcode.com/problems/minimum-cost-to-cut-a-stick/


class Solution {
public:
    int M = 1e9;
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());
        
        int size = cuts.size();
        vector<vector<int>> dp(size, vector<int>(size, M));

        for(int i = 0; i < size - 1; ++i){
            dp[i][i + 1] = 0;
        }

        for(int len = 2; len < size; len++) {
            for(int i = 0; i < size - len; i++) {
                int j = len + i;
                for(int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
                }
            }
        }
        return dp[0][size - 1];
    }
};