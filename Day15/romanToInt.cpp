// Problem Link :- https://leetcode.com/problems/roman-to-integer/ 


class Solution {
public:
    int romanToInt(string s) {
        map<char, int> translate {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int temp = 0;
        int ans = 0;
        for (auto digit : s) {
            auto curr = translate[digit];
            if (temp < translate[digit]) {
                ans += curr - 2*temp;
            } else {
                ans += curr;
            }
            
            temp = curr;
        }
        
        return ans;
    }
};