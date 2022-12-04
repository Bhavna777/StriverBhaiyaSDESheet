// Problem Link :- https://leetcode.com/problems/longest-substring-without-repeating-characters/ 

int lengthOfLongestSubstring(string s) {
    vector < int > mp(256, -1);

    int i = 0, j = 0;
    int n = s.size();
    int ans = 0;
    while (i < n) {
    if (mp[s[i]] != -1)
        j = max(mp[s[i]] + 1, j);

    mp[s[i]] = i;

    ans = max(ans, i - j + 1);
    i++;
    }
    return ans;
}