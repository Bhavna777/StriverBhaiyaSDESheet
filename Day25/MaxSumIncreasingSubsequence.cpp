// Problem Link :- https://www.codingninjas.com/codestudio/problems/1112624


#include <bits/stdc++.h> 
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	vector<int> dp(n,-1);
    dp[0] = rack[0];
    
    for(int i=1; i<n; i++){
        int temp = rack[i];
        for(int j=0; j<i; j++){
            if(rack[j] < rack[i]){
                temp = max(temp, rack[i]+dp[j]);
            }
        }
        dp[i] = temp;
    }
    return *max_element(dp.begin(),dp.end());
}