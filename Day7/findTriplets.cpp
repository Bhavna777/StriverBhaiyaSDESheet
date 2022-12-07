// Problem Link :- https://leetcode.com/problems/3sum 


vector<vector<int>> ans; 
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i=0; i<n-2; i++) {
        if (i == 0 || (i > 0 && nums[i] != nums[i-1])) {
            int l = i+1;
            int r = n-1;
            int sum = 0 - nums[i];
            
            while (l < r) {
                if (nums[l] + nums[r] == sum) {
                    vector<int>temp; 
                    temp.push_back(nums[i]); 
                    temp.push_back(nums[l]); 
                    temp.push_back(nums[r]); 
                    ans.push_back(temp);
                    
                    while (l < r && nums[l] == nums[l+1]) l++;
                    while (l < r && nums[r] == nums[r-1]) r--;
                    
                    l++;
                    r--;
                } 
                else if (nums[l] + nums[r] < sum) l++;
                else r--;
            }
        }
    }
    return ans;