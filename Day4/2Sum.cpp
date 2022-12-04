// Problem Link :- https://leetcode.com/problems/two-sum/ 


// Approach - 1  TC - O(N2), SC - O(1) - Brute Force
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(nums[i] == target){
                return {i, j};
            }
        }
    }

    return {i, j};
}


// Approach - 2  TC - O(NlogN), SC - O(N) - Two Pointer Approach 


vector<int> twoSum(vector<int>& nums, int target) {
    vector<int>ans, store;
    store = nums;
    int n = nums.size();
    sort(store.begin(), store.end());
    int start = 0;
    int end = n - 1;
    int n1, n2;
    while(start < end){
        if(store[start] + store[end] == target){
            n1 = store[start];
            n2 = store[end];
            break;
        }else if(store[start] + store[end] < target){
            start++;
        }else{
            end--;
        }
    }
    
    for(int i=0; i<n; i++){
        if(nums[i] == n1){
            ans.push_back(i);
        }else if(nums[i] == n2){
            ans.push_back(i);
        }
    }

    return ans;
}


// Approach - 3  TC - O(N), SC - O(N) - Hashing

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int>ans;
    int n = nums.size();
    unordered_map<int, int>mp;

    for(int i=0; i<n; i++){
        int key = target - nums[i];
        if(mp.find(key) != mp.end()){
            ans.push_back(i);
            ans.push_back(mp[key]);
            return ans;
        }

        mp[nums[i]] = i;
    }
    
    return ans;
}