// Problem Link :- https://www.codingninjas.com/codestudio/problems/1094901


#include <bits/stdc++.h> 
bool wordBreak(vector < string > & arr, int n, string & target) {
    if(arr.size()==0){
        return false;
    }
    vector<bool>dp(target.size()+1,false);
    dp[0] = true;
    for(int i=1; i<=target.size(); i++){
        for(int j=i-1; j>=0; j--){
            if(dp[j]){
                string word = target.substr(j, i-j);
                auto it = find(arr.begin(), arr.end(),word);
                if(it != arr.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    return dp[target.size()];
}