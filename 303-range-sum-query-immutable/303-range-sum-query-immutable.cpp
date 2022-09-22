class NumArray {
public:
    vector<int> prefixSum;
    
    NumArray(vector<int>& nums) {
        prefixSum.assign(nums.size()+1, 0);
        
        prefixSum[0]=0;
        
        for (int i=1; i<=nums.size(); i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return prefixSum[right+1]-prefixSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */