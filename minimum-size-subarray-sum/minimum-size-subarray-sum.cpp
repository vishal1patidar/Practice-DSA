class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int n = nums.size();
        
        int start = 0, end = 0;
        int sum = nums[0];
        
        int ans = INT_MAX;
        while (start <= end && end < n){
            if (sum < k){
                ++end;
                if (end < n) sum += nums[end];
            }
            
            else{   // sum >= k
                ans = min(ans, end-start+1);
                sum -= nums[start];
                start++;
            }
        }
        
        if (ans == INT_MAX){
            return 0;
        }
        
        return ans;
    }
};