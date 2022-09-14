class Solution {
public:
int solve(vector<int>& nums) {
int maxRange=nums[0];
int step=nums[0];
int jump=1;

    if(nums.size()==1) {
        return 0; 
    } 
    else if(nums[0] == 0) {
        return -1; 
    } 
    else {
        for(int i=1; i<nums.size()-1; i++) { 
            // if(i == nums.size()-1) {
            //     break; 
            // }
            maxRange = max(maxRange, i+nums[i]); 
            step--; 
            if(step == 0) {
                jump++; 
                if(i >= maxRange) {
                    return -1; 
                } 
                step = maxRange - i; 
            } 
            
        }
    } 
    
    return jump; 
}
int jump(vector<int>& nums) {
    return solve(nums); 
}
};