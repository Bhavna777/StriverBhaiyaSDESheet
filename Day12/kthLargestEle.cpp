// Problem Link :- https://leetcode.com/problems/kth-largest-element-in-an-array/ 


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            pq.push(nums[i]);
        }

        int temp = k - 1;

        while (temp > 0) {
            pq.pop();
            temp--;
        }

        return pq.top();
    }
};