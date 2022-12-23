class Solution {
public:
    int getmax(int ind,int buy,vector<int>& prices,vector<vector<int>>& dp)
    {
        if(ind >=prices.size())return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        int profit=0;
        if(buy)
        {
            profit=max(-prices[ind]+getmax(ind+1 ,0 ,prices ,dp) , 0 +getmax(ind+1 ,1, prices ,dp));
        }
        else
        {
            profit=max(prices[ind]+ getmax(ind+2, 1, prices ,dp), getmax(ind+1, 0, prices, dp));
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1)); // 2 for considering both buy and sell
        return getmax(0,1,prices,dp);
    }
};