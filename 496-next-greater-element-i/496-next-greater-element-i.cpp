// INTUTION: is to create a hashmap mapping elements of nums1 with its indexes so that while traversing the nums2 we can check if or not this number exist in num2 so as to find next greater element or can we skip it.
// Also hashmap will help us to put the next greater element in resultant vector at its correct position
// Ex: nums1 = [1 4 2] nums2 [ 1 3 4 2 ]
// Hashmap : 1 - 0 , 4-1 , 2 -2
// So we'll first iterate over nums2 check if 1 is present in hashmap (if its in hashmap means its in nums1) okay , next iterate through nums2 from i+1 and find the next greater element if found that is 3 in case we are finding next greater for 1 so insert it at position where 1 is there in nums 2
// resultan t[-1 -1 -1 ] initially
// after next greater for 1 = , resultant [-1 , 3, -1]
// And this index where 1 is there we'll get it from hashmap.
// So insert 3 at 1st position of resultant array.
// We do so because order is maintained in resultant array acc to question if next greater of 1th position elemt is found it will be inserted in resulatant array 
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       map<int,int> mp;
        vector<int> ans(nums1.size(),-1);
        for(int i=0;i<nums1.size();i++){
            mp[nums1[i]]=i;
        }
        for(int i=0;i<nums2.size();i++){
            if(mp.find(nums2[i])!=mp.end()){
                for(int j=i+1;j<nums2.size();j++){
                    if(nums2[j]>nums2[i]){
                        ans[mp[nums2[i]]]=nums2[j];
                        break;
                    }
                }              
            }
        }
        return ans;
    }
};