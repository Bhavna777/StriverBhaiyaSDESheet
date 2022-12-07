// Problem Link :- https://leetcode.com/problems/max-consecutive-ones 


int findMaxConsecutiveOnes(vector<int>& nums) {
    int ans = 0;
    int count = 0;
    int n = nums.size();
    for(int i=0; i<n; i++){
        if(nums[i] == 1){
            count++;
        }else{
            count = 0;
        }

        ans = max(ans, count);
    }


    return ans;
}