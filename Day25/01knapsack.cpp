// Problem Link :- https://www.codingninjas.com/codestudio/problems/1072980


#include<bits/stdc++.h>

int solve(vector<int>& weights, vector<int>& values, int index, int w, vector<vector<int>>&dp){
    
    if(index == 0){
        if(weights[0] <= w){
            return values[0];
        }else{
            return 0;
        }
    }
    
    if(dp[index][w] != -1){
        return dp[index][w];
    }
        
    int notTaken = 0 + solve(weights, values, index-1, w, dp);
    int taken = INT_MIN;
    
    if(weights[index] <= w){
        taken = values[index] + solve(weights, values, index-1, w-weights[index], dp);
    }
        
    return dp[index][w] = max(notTaken, taken);
}


int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>>dp(n,vector<int>(w+1,-1));
    return solve(weights, values, n-1, w, dp);
}