class Solution {
    bool f(int index,vector<int> &nums,int n,vector<int> &dp){
        
        if(index == n){
            return true;
        }
        
        if(nums[index]==0)
            return false;
        
        if(dp[index]!=-1)
            return dp[index];
        
        if(index + nums[index] > n)
            return dp[index] = true;
        
        bool ans = false;
        
        for(int i = 1;i <= nums[index];i++)
        {
            if(index+i<=n){
                if(dp[index+i]==-1)
                dp[index+i] = f(index + i,nums,n,dp);
                ans = ans || dp[index+i];
            }
        }        
        
        return dp[index] = ans;        
    }
    
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(0,nums,nums.size()-1,dp);
    }
};