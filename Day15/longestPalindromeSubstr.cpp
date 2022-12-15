// Problem Link :- https://leetcode.com/problems/longest-palindromic-substring/ 


class Solution {
public:

    bool isPalindrome(string s){
        int start = 0;
        int end = s.size() - 1;
        while(start <= end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        if(s.size() == 0 || s.size() == 1){
             return s;
        }
        string ans;
        int n = s.size();
        int maxlen = 0;
        for(int i=0; i<n-maxlen; i++){
            for(int j=n-1; j>=i+maxlen; j--){
                if(s[j] != s[i]){
                     continue;
                }
                string str = s.substr(i, j - i + 1);
                
                if(isPalindrome(str) && str.size() > maxlen){
                    maxlen = str.size();
                    ans = str;
                }
            }
        }
        return ans;
    }
};