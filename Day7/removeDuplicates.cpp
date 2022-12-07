// Problem Link :- https://leetcode.com/problems/remove-duplicates-from-sorted-array 


int removeDuplicates(vector<int>& nums) {
    int i = 0;
    int n = size(nums);
    for(int j=1; j<n; j++){
        if(nums[i]!=nums[j]){
            i++;
            nums[i] = nums[j];
        }
    }
    
    return i+1;
}
