class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort (nums.begin(),nums.end());
        for(int i =nums.size()-1;i>=2;i--)  //iterarting from end -->and checking all the possible combination
    {
        if(nums[i]<(nums[i-1]+nums[i-2]))//if a<b+c
        {
            return nums[i]+nums[i-1]+nums[i-2]; //return perimeter
        }
    }
    return 0;
    }
};