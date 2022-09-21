class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), res = -1e9;
        vector<pair<int,int>> dp(n+1);
        dp[0] = {1,1};
        for (int i=0;i<n;i++){
            if (nums[i]<0){
                dp[i+1].first = max(nums[i] , nums[i]*dp[i].second);
                dp[i+1].second = min(nums[i] , nums[i]*dp[i].first);
            }
            else{
                dp[i+1].first = max(nums[i] , nums[i]*dp[i].first);
                dp[i+1].second = min(nums[i] , nums[i]*dp[i].second);
            }
            res = max(res,dp[i+1].first);
            res = max(res,dp[i+1].second);
        }
        return res;
    }
};