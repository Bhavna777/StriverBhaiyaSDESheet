// Problem Link :- https://www.codingninjas.com/codestudio/problems/982770


#include<bits/stdc++.h>

int dp[101][10001];
int func(int k , int n)
{
    if(n==1 || n==0){
        return n;
    }
    if(k==1){
        return n;
    }
    if(dp[k][n] != -1){
       return dp[k][n];
   }
   int ans = INT_MAX;

   int l = 1;
   int h = n;

   while(l<=h){
       int mid = (l + (h-l)/2);
       int a=func(k , n-mid);
       int b=func(k-1 , mid-1);
       int temp = 1+max(a,b);
       if(a > b){
           l = mid + 1;
       }else{
           h = mid - 1;
       }

       ans = min(ans, temp);
   }

   return dp[k][n] = ans;
}


int cutLogs(int k, int n)
{
    memset(dp , -1 , sizeof(dp));
    return func(k, n);
}