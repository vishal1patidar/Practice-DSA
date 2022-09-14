class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int lower=0, upper=nums.size()-1, mid;
        
        while(upper-lower>1)
        {
            mid = (upper + lower) / 2;
            target>nums[mid]? lower=mid+1 : upper=mid;
        }
        if(target==nums[upper]) return upper;
        if(target==nums[lower]) return lower;
        return -1;
    }
};