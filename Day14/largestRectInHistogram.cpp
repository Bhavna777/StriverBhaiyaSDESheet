// Problem LInk :- https://leetcode.com/problems/largest-rectangle-in-histogram/ 


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack < int > s;
        int left[n], right[n];
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
            }
            if (s.empty())
            left[i] = 0;
            else
            left[i] = s.top() + 1;
            s.push(i);
        }
        while (!s.empty())
            s.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i])
            s.pop();

            if (s.empty())
            right[i] = n - 1;
            else
            right[i] = s.top() - 1;

            s.push(i);
        }
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, heights[i] * (right[i] - left[i] + 1));
        }
        return maxi;
        
    }
};