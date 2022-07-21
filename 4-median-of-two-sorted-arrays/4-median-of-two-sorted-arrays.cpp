class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        
        for(int i = 0; i<nums2.size(); i++){
        nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
         int count = nums1.size();
        if(count%2==1){
            int f = (nums1.size()+1)/2.0;
            return nums1[f-1];
        }else{
            int f = (nums1.size()+1)/2.0;
            return (nums1[f-1]+nums1[f])/2.0;
        }
    }
};