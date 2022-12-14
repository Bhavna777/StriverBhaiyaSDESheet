// Problem LInk :- https://leetcode.com/problems/sliding-window-maximum/ 


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if (k == 0) return ans;

        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i< n; i++) {
            while (!pq.empty() && pq.top().second <= i-k)
                pq.pop();
            pq.push({nums[i],i});
            if (i >= k-1)
                ans.push_back(pq.top().first);
        }
        return ans;
    }
};