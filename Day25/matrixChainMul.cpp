// Problem Link :- https://www.codingninjas.com/codestudio/problems/975344


#include <bits/stdc++.h> 

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>>dp(N, vector<int>(N, INT_MAX));
    for(int i=0; i<N-1; i++){
        dp[i][i+1] = 0;
    }
    for(int gap = 2; gap<N; gap++){
        for(int i = 0; i+gap<N; i++){
            int j = i + gap;
            for(int k = i+1; k<j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + arr[i]*arr[k]*arr[j]);
            }
        }
    }
    return dp[0][N-1];
}