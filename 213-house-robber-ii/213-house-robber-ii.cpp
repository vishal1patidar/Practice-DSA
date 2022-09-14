class Solution {
public:
    int rob(vector<int>& nums) {
        int n = size(nums);
        if(n == 1) return nums[0];
        vector<int> dp(n, 0), dp1(n, 0);
        
        dp[0] = nums[0];
        for(int i = 1; i < n-1; i++) {
            int take = nums[i];
            if(i > 1) take += dp[i - 2];
            int leave = dp[i - 1];
            
            dp[i] = max(take, leave);            
        }
        
        dp1[0] = 0;
        dp1[1] = nums[1];
        for(int i = 2; i < n; i++) {
            int take = nums[i] + dp1[i - 2];
            int leave = dp1[i - 1];
            
            dp1[i] = max(take, leave);            
        }
       return max(dp1[n - 1], dp[n-2]);
    }
};