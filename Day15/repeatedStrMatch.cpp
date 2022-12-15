// Problem Link :- https://leetcode.com/problems/repeated-string-match/ 



class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string temp="";
        int count = 0;
        while(temp.size()<b.size()){
            temp = temp + a;
            count++;
        }
        if(temp.find(b)!=string::npos)
            return count;
        temp = temp + a;
        count++;
        if(temp.find(b)!=string::npos)
            return count;
        
        return -1;
    }
};