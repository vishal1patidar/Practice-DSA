class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    int sum = 0;
    int i = 0;
   while(i<=nums.size()-1){
       
       sum+=min(nums[i],nums[i+1]);
       i=i+2;
       
   }
    return sum;
    }
};