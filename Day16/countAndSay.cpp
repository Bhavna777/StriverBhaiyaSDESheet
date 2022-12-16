// Problem Link :- https://leetcode.com/problems/count-and-say/ 


class Solution {
public:
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        } 
        string s = countAndSay(n - 1);

        string ans = "";
        int m = s.size();
        for(int i = 0; i < m; i++){
            int count = 1;
            while(i < m - 1 && s[i] == s[i + 1]){
                i++;
                count++;
            }
            ans.append(to_string(count) + s[i]);
        }
        return ans;
    }
};