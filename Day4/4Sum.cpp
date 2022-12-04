// Problem Link :- https://leetcode.com/problems/4sum/ 

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int> > ans;
    
    if (nums.empty())
        return ans;
    
    int n = nums.size();
    
    sort(nums.begin(),nums.end());

    for (int i = 0; i < n; i++) {
    
        long long int target3 = target - nums[i];
    
        for (int j = i + 1; j < n; j++) {
        
            long long int target2 = target3 - nums[j];
        
            int start = j + 1;
            int end = n - 1;
        
            while(start < end) {
                int twoSum = nums[start] + nums[end];
                if (twoSum < target2){
                    start++;
                }else if (twoSum > target2){
                    end--;   
                }else{
                    vector<int>temp(4, 0);
                    temp[0] = nums[i];
                    temp[1] = nums[j];
                    temp[2] = nums[start];
                    temp[3] = nums[end];
                    ans.push_back(temp);
                
                    while (start < end && nums[start] == temp[2]){
                        start++;   
                    }
                
                    while (start < end && nums[end] == temp[3]){
                        end--;   
                    }
            
                }
            }
            
            while(j + 1 < n && nums[j + 1] == nums[j]){
                j++;   
            }
        }
    
        while (i + 1 < n && nums[i + 1] == nums[i]){
            i++;   
        }
    
    }

    return ans;
}