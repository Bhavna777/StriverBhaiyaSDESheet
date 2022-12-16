// Problem Link :- https://leetcode.com/problems/compare-version-numbers 


class Solution {
public:
    int compareVersion(string version1, string version2) {
        for (stringstream ss1(version1), ss2(version2); ss1 || ss2;){
            string s; 
            int n1 = getline(ss1, s, '.')? stoi(s) : 0;         
            int n2 = getline(ss2, s, '.')? stoi(s) : 0;
            if (n1 != n2){
                if(n1 > n2){
                    return 1;
                }else{
                    return -1;
                }
            }
        }
        return 0;
    }
};