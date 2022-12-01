// Problem Link :- https://leetcode.com/problems/sort-colors 

void sortColors(vector<int>& nums) {
    int n = nums.size();
    int start = 0;
    int end = n - 1;
    int temp = 0;
    while(temp<=end){
        if(nums[temp]==0){
            swap(nums[start], nums[temp]);
            temp++;
            start++;
        }
        else if(nums[temp]==1){
            temp++;
        }else{
            swap(nums[temp], nums[end]);
            end--;
        }
    }
}