class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total_sum = 0;
        for(auto i : nums)
            total_sum += i;
        int left_sum = 0;
        for(int i = 0 ; i < nums.size(); i++)
        {
            if(left_sum == total_sum - left_sum - nums[i])
                return i;
            left_sum += nums[i];
        }
        return -1;
    }
};