// Problem Link :- https://leetcode.com/problems/longest-consecutive-sequence/ 

int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if(n == 0 ){
        return 0;
    }
    
    sort(nums.begin(),nums.end());
    
    int ans = 1;
    int prev = nums[0];
    int curr = 1;
    
    for(int i = 1;i < n;i++){
        if(nums[i] == prev+1){
            curr++;
        }
        else if(nums[i] != prev){
            curr= 1;
        }
        prev = nums[i];
        ans = max(ans, curr);
    }
    return ans;
}