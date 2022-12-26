// Problem Link :- https://www.codingninjas.com/codestudio/problems/873266


#include <bits/stdc++.h> 
bool isPalindrome(string str, int i, int j){
    while(i<=j){
        if(str[i]!=str[j]){
            return false;
        }
        i++;
        j--;
    }
    
    return true;
}
int palindromePartitioning(string str) {
    int n = str.length();
    vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

    for(int gap = 1; gap<n; gap++){
        for(int i = 0; i+gap<n ;i++){
            int j = i + gap;
            if(isPalindrome(str, i, j)){
                dp[i][j] = 0;
            }else{
                dp[i][j] = INT_MAX;
                for(int k=i; k<j; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + 1);
                }
            }
        }
    }
    return dp[0][n-1];
}