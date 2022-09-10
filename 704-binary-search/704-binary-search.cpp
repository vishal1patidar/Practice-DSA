class Solution {
public:
    int search(vector<int>& nums, int target) {
       //return binary_search(nums.begin() ,  nums.end() , );
        int start = 0;
        int end = nums.size()-1;
        int mid = start + (end-start)/2;
        
        while(start <= end)
        {
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] > target)
            {
                end = mid-1;
            }
            else{
                start = mid +1;
            }
            mid = start + (end-start)/2;
        }
        return -1;
        
    }
};