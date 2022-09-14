class Solution {
public:
    vector<int> solveUsingBounds(vector<int>&nums , int target)
    {
        // lower returns >= and upper bound returns > pointer address
        int first_pos = -1,last_pos=-1;
        
        // if value doesn't exist 
        if(!binary_search(begin(nums),end(nums),target)) return{ first_pos,last_pos};
        
        first_pos = lower_bound(begin(nums),end(nums),target)-begin(nums);
        last_pos = upper_bound(begin(nums),end(nums),target)-begin(nums)-1;
        
        
       return{ first_pos,last_pos}; 
        
    }
    vector<int> solveTWoTimesBS(vector<int>&nums , int target)
    {
        int low =0;
        int high = size(nums)-1;
        int first_pos = -1,last_pos=-1;

         while(low<=high){
            int mid = low +( high-low)/2;
            
            if(nums[mid]==target){
                first_pos = mid;
                high= mid-1;
            }
            else{
                if(nums[mid]<target){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
//         last pos B.S
        low =0;high=size(nums)-1;
        while(low<=high){
            int mid = low +( high-low)/2;
            
            if(nums[mid]==target){
                last_pos = mid;
                low= mid+1;
            }
            else{
                if(nums[mid]<target){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        // res.push_back(last_pos);
        
        return{ first_pos,last_pos};
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        // binary search 
       return solveTWoTimesBS(nums,target);
        // return solveUsingBounds(nums,target);
        
    }
};