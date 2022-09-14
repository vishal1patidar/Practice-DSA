class Solution {
public:
    int rob(vector<int>& nums) {
        
        int in = nums[0];
        int ex = 0;
        int exn;
        
        for(int i=1;i<nums.size(); i++)
        {
            exn = max(in, ex);
            
            in = ex + nums[i];
            ex = exn;
        }
        
        return max(in, ex);
    }
};