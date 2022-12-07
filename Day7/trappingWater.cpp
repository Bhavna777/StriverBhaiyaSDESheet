// Problem Link :- https://leetcode.com/problems/trapping-rain-water 


int trap(vector<int>& height) {
    int ans = 0;
    int n = height.size();
    int start = 0;
    int end = n - 1;
    int s = 0;
    int e = 0;
    while (start <= end) {
        if (height[start] <= height[end]) {
            if (height[start] >= s) {
                s = height[start];
            }else{
                ans += s - height[start];
            }
            start++;
        }else{
            if (height[end] >= e) {
                e = height[end];
            }else{
                ans += e - height[end];
            }
            end--;
        }
    }
    return ans;
}