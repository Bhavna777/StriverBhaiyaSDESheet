// Problem Link :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock/ 

int maxProfit(vector<int>& prices) {
    int ans=0;
    int mini=prices[0];
    for(int i=1;i<prices.size();i++){
        mini=min(prices[i],mini);
        ans=max(ans,(prices[i]-mini));
    }
    return ans;
}