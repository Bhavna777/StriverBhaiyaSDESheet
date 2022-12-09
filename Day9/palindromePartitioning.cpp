// Problem Link :- https://leetcode.com/problems/palindrome-partitioning 



bool isPalindrome(string &s, int start, int end){
    int mid = start + ((end - start) >> 1);

    while (start <= mid){
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    
    return true;
}

void partitioner(string &s, int start, int n, vector<string>&temp, vector<vector<string>> &ans)
{
    if (n <= 0){
        ans.push_back(temp);
        return;
    }
    
    for (int i=1; i<=n; i++){
        if (isPalindrome(s, start, start+i-1)){
            string ss = s.substr(start, i);
            temp.push_back(ss);
            partitioner(s, start+i, n-i, temp, ans);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>>ans;
    vector<string> temp;
    int n = s.length();

    partitioner(s, 0, n, temp, ans);
    
    return ans;
}
};