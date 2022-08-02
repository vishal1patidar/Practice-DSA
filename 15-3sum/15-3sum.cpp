class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n<3)return {}; // cant form 3sum with less than 3 element
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < n-2; ++i){
            if(i==0 || nums[i] != nums[i-1]){ // if same element in 'i', duplicate answer in next iteration
                int j= i+1, k=n-1;
                while(j<k){
                    int sum= nums[i] + nums[j] + nums[k];
                    if(sum==0){
                        res.push_back({nums[i],nums[j],nums[k]});
                        while(j<k && nums[j]==nums[j+1]) j++; // if duplicate element found it skips
                        while(j<k && nums[k]==nums[k-1]) k--; // if duplicate element found it skips
                        j++; k--;
                    }
                    else if( sum>0) k--; // if sum is >0, decrement k, as array is in increasing order
                    else j++;
                }
            }
        }
        return res;
    }
};