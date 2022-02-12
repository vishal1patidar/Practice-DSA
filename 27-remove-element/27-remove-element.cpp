class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        auto end = std::remove_if(nums.begin(),nums.end(), [&](int const &i) {
            return i == val; 
          });
        
        nums.erase(end, nums.end());
        
        return nums.size();
    }
};