// Problem Link :- https://leetcode.com/problems/single-element-in-a-sorted-array/description/ 



int singleNonDuplicate(vector<int>& nums) {
    int start = 0;
    int end = nums.size() - 2;
    int mid = start + (end - start)/2;
    
    while(start <= end){
        if (mid % 2 == 0) {
            if (nums[mid] != nums[mid + 1]) 
                end = mid - 1;
            else
                start = mid + 1;
        } else {
            if (nums[mid] == nums[mid + 1]) 
                end = mid - 1;
            else
                start = mid + 1;
        }

        mid = start + (end - start)/2;
    }

    return nums[start];
}