class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
    int idx = 0;
    int n = nums.size();
    while(i<n){
        if(nums[i]!=0){
            nums[idx] = nums[i];
            idx++;
        }
        i++;
    }
    while(idx<n){
        nums[idx] = 0;
        idx++;
    }
    
    }
};