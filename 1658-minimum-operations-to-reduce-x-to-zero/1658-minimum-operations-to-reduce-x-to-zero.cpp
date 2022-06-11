class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = accumulate(nums.begin(), nums.end(), 0);  // Total sum
        int target = total - x;                               // target
		int left = 0, right = 0;                              // Two pointers
        int ans = -1; 
        int n = nums.size();
        
        if(target<0) return -1;
        if(target==0) return nums.size();
        
        while(left < n || target < 0){
            if(target>0) target-=nums[left++];
            else target+=nums[right++];
            if(target==0) ans=max(ans, left-right);
        }
        
        return ans == -1 ? -1 : n - ans;
    }
};