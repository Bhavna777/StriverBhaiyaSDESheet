// Problem Link :- https://leetcode.com/problems/majority-element/ 

int majorityElement(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start)/2;
    
    return nums[mid];
}