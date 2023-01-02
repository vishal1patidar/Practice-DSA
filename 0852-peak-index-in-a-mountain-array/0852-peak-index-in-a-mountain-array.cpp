class Solution {
public:
    int findpeak(vector<int>& nums,int s,int e){
        //base case
       if(s==e){
           return -1;
       }
        int mid=s+(e-s)/2;
         if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1])
    {
        return mid;
    }
        if(nums[mid]<nums[mid+1]){
            return findpeak(nums,mid+1,e);
        }
        else{
            return findpeak(nums,s,mid);
        }
        return -1;
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        int ans=findpeak(arr,0,arr.size()-1);
        return ans;
    }
};