// Problem Link :- https://leetcode.com/problems/maximum-product-subarray/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans;
        int curMax;
        int curMin;
        ans = curMax = curMin = nums[0];

        int n = nums.size();
        for (unsigned int i=1; i<n; i++) {
            int temp = curMin;
            curMin = min(nums[i], min(curMax*nums[i], curMin*nums[i]));
            curMax = max(nums[i], max(curMax*nums[i], temp*nums[i]));
            ans = max(ans, curMax);
        }
        
        return ans;
    }
};