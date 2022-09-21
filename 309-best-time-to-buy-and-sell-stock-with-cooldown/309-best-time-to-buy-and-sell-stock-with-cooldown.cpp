class Solution {
public:
    int helper(vector<int> &prices,int ind,int n,vector<vector<int>> &dp,int st)
    {
        if(ind >= n)
            return 0;
        if(dp[ind][st] != -1 )
            return dp[ind][st];
        
        if(st)
        {
            int buy = -prices[ind] + helper(prices,ind+1,n,dp,0);
            int not_buy = 0 + helper(prices,ind+1,n,dp,1);
            
            return dp[ind][st] = max(buy,not_buy);
        }
        else
        {
            
        
        int sell = prices[ind] + helper(prices,ind+2,n,dp,1);
        int not_sell = 0 + helper(prices,ind+1,n,dp,0);
        
        return dp[ind][st] =  max(sell,not_sell);
        }
        
        
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        vector<vector<int>> dp(n,vector<int>(2,-1));
        
        return helper(prices,0,n,dp,1);
    }
};