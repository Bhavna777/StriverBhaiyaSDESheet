// Problem Link :- https://leetcode.com/problems/coin-change/


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, INT_MAX); 
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (auto &coin : coins) {
                if (coin > i){
                    break;
                }
                if (dp[i - coin] == INT_MAX){
                    continue;
                }
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        if(dp[amount] == INT_MAX){
            return -1;
        }else{
            return dp[amount];
        }
    }
};