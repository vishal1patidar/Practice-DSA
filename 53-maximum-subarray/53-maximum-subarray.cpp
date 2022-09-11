class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=nums[0];
        int curMax=0;
        for(int i =0 ;i< nums.size();i++){
            curMax+= nums[i];
            if (curMax>maxSum) maxSum=curMax;
            if (curMax<0) curMax=0;
        }
        return maxSum;
    }
};