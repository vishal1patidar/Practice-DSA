// Time Complexity :- O(Log(n))
// Space Complexity :- O(1)


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto low = lower_bound(nums.begin(),nums.end(),target);
        auto up = upper_bound(nums.begin(),nums.end(),target);
        
        if(low == nums.end() || *low != target)    return {-1,-1};
        
        int first = low - nums.begin();
        int last = up - nums.begin()-1;
        
        return {first ,last};
    }
};