// Problem Link :- https://leetcode.com/problems/longest-increasing-subsequence/


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<int>v(n, 1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    v[i] = max(v[i], v[j] + 1);
                } 
            }
            ans = max(ans, v[i]);
        }
        
        return ans;
    }
};