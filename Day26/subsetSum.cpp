// Problem Link :- https://leetcode.com/problems/partition-equal-subset-sum/


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }

        if (sum % 2){
            return false;
        }

        vector<double>dp(sum/2 + 1);
        dp[0] = 1;

        for (int i = 1; i <= n; ++ i){
            for (int j = sum/2; j >= nums[i - 1] ; j--){
                dp[j] +=  dp[j - nums[i - 1]];
            }
        }

        return dp[sum/2];
    }
};