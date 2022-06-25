class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        int leftSum=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
        }
        int rightSum=sum-nums[0];
        
        
        for(int i=0;i<n;i++)
        {
            if(leftSum==rightSum)
                return i;
            if(i<n-1){
                rightSum=rightSum-nums[i+1];
                leftSum=leftSum+nums[i];
            }
        }
        return -1;
    }
};
