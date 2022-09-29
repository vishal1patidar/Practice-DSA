class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int N = nums.size();
        
        vector<int> dp(N);
        dp[0] = 1;
        int mx = 1;
        
        for (int i=1; i < N; i++) {
            int tmp = 0;
            for (int j=0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    tmp = max(tmp, dp[j]);
                }
            }
            
            dp[i] = tmp + 1;
            mx = max(mx, dp[i]);
        }
    
        vector<int> dp2(N);
        dp2[0] = 1;
        
        for (int i=1; i < N; i++) {
            int tmp = 0;
            int val = dp[i];
            for (int j=0; j < i; j++) {
                if ((dp[j] == val-1) and (nums[j] < nums[i])) {
                    tmp += dp2[j];
                }
            }
            
            dp2[i] = tmp == 0 ? 1 : tmp;
        }
        
        int count = 0;
                    
        for (int i=N-1; i >= 0; i--) {
            if (dp[i] == mx)
                count += dp2[i];
        }
        
        return count;
    }
};