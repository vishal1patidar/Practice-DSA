class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int> &dp){
        if(i==nums.size()-1 || i==nums.size()-2) return nums[i];
        
        if(dp[i]!=INT_MIN) return dp[i];
        
        int maxsum=nums[i];
        int sum=nums[i];
        
        int temp=solve(nums,i+2,dp);
        sum+=temp;
        maxsum=max(sum,maxsum);
        
        if(i+3 < nums.size()){
            sum-=temp;
            temp=solve(nums,i+3,dp);
            sum+=temp;
            maxsum=max(sum,maxsum);
        }
        
        dp[i]=maxsum;
        return dp[i];
        
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        
        vector<int> dp(nums.size()+1,INT_MIN);
        
        return max(solve(nums,0,dp),solve(nums,1,dp));
        
    }
};