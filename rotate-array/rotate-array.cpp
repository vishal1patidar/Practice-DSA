class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        fun(nums,0,k);
    
        
       
    }
    void fun(vector<int>&nums,int start, int k)
    {   int len=nums.size()-start;
        if(len==1)
            return;
        k=k%len;
     if(!k)
         return;
        
     int left=0;
     int right=nums.size()-k;
        k=k%(len);
        while(left<k)
        {swap(nums[left+start],nums[right+left]);
          left++;
         
        }
        
        fun(nums,start+k,k);
        
    }

};