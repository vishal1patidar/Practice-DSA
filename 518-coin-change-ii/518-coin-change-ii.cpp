class Solution {
public:
    
    int amt;
    
    int solve(vector<int> &nums, int val, int index, vector<vector<int>> &dp)
    {
        if(val > amt) return 0;
        if(val == amt) return 1;
        
        if(dp[index][val] != -1) return dp[index][val];
        
        int sum = 0;
        for(int i=index; i<nums.size(); i++)
        {
            sum += solve(nums, val+nums[i], i, dp);
        }
        
        return dp[index][val] = sum;
    }
    
    int change(int amount, vector<int>& coins) {
        
        vector<vector<int>> dp(coins.size()+1, vector<int> (amount+5001, -1));
        amt = amount;
        return solve(coins, 0, 0, dp);
    }
};