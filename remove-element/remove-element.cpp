class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int safe = nums.size()-1 ;
        int j = nums.size()-1 ;
        
        while(j >= 0){
            if(nums[j] == val){
                swap(nums[j] , nums[safe]);
                
                safe-- ;
                j-- ;
            }else{
                j-- ;
            }
        }
       
        return safe+1; 
    }
};