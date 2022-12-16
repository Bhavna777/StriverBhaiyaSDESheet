// Problem Link :- https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/ 


class Solution {
public:

    vector<int> kmp(string needle) {
        int n = needle.size();
        vector<int> v(n, 0);
        for (int i = 1, len = 0; i < n;) {
            if (needle[i] == needle[len]) {
                v[i++] = ++len;
            } else if (len) {
                len = v[len - 1];
            } else {
                v[i++] = 0;
            }
        }
        return v;
    }

    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (!n) {
            return 0;
        }
        vector<int> v = kmp(needle);
        for (int i = 0, j = 0; i < m;) {
            if (haystack[i] == needle[j]) { 
                i++, j++;
            }
            if (j == n) {
                return i - j;
            }
            if (i < m && haystack[i] != needle[j]) {
                j ? j = v[j - 1] : i++;
            }
        }
        return -1;
    }
};