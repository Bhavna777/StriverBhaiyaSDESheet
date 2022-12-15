// Problem Link :- https://leetcode.com/problems/string-to-integer-atoi/ 


class Solution {
public:
    int myAtoi(string s) {
        if (s.empty()){
            return 0;
        } 
        int i = 0;
        int sign = 1;

        while (i + 1 < s.size() && isspace(s[i])){
            i++;
        }
        long ans = 0;
        if (s[i] == '-' || s[i] == '+'){
            sign = 44 - s[i++];
        }
        while (i < s.size()) {
            if (isdigit(s[i])){
                ans = 10 * ans + s[i++] - '0';
            }else{
                return ans * sign;
            } 
            if (ans > INT_MAX){
                if(sign == -1){
                    return INT_MIN;
                }else{
                    return INT_MAX;
                }
            }
        }
        return ans * sign;
    }
};