class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int potential_ans = 0;
        for(int i=0; i<nums.size(); i++){  
            if(nums[i] == 1){
                potential_ans++;
            }
            if(nums[i] == 0){
                ans = max(ans, potential_ans);
                potential_ans = 0;
            }
        }
        ans = max(ans, potential_ans);
        return ans;
    }
};