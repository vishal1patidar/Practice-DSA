class Solution {
public:
    bool fun(int idx,vector<int>& nums,int n,vector<int>& dp){
        if(idx>=n-1) return 1;
        if(nums[idx]==0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        for(int i=1;i<=nums[idx];i++){
            bool ans=fun(idx+i,nums,n,dp);
            if(ans) return dp[idx]=1;
        }
        return dp[idx]=0;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }
        vector<int> dp(n+maxi+10,-1);
        return fun(0,nums,n,dp);
    }
};