class Solution {
public:
    vector<int> mem;
    int maxRob(vector<int> &nums , int i){
        if (mem[i] != -1) return mem[i];
        if (i >= nums.size()) return 0;
        
        return mem[i] = max(nums[i] + maxRob(nums , i+2) , maxRob(nums, i+1));
    }
    int rob(vector<int>& nums) {
        mem = vector<int>(nums.size()+3 , -1);
        return maxRob(nums , 0);
    }
};