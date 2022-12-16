// Problem Link :- https://leetcode.com/problems/valid-anagram/ 


class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n != m)
            return false;
            
        map<char, int>mp1;
        map<char, int>mp2;
        
        for(int i=0; i < n; i++)
        {
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        
        if(mp1 != mp2)
            return false;
        else
            return true;
    }
};