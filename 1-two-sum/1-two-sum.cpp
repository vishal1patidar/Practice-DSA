// Brute Forces Approach

// Here, we are running two loops. Where i indicates outer loop and j indicates inner loop.
// Example :
// nums = [2,7,11,15], target = 9
// When i=0 then inner loop will run from j=1(means i+1) to j=n(size of vector) It will check whether nums[0] + nums[j] == target if yes then we will push that index in new vector which we have to return as answer. When i reach to i=n then our code will terminate.
// Time complexity of these code is O(n^2). We can futher optimized the code by using

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int length = nums.size();
        vector<int> ans;
        for(int i=0;i<length;i++){
            for(int j=i+1;j<length;j++){
                if(nums[i]+nums[j]==target){
                    ans.push_back(i);
                    ans.push_back(j);
					break;
                }
            }
        }
        return ans;
    }
};
// **Two Pointer Approach **

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n=nums.size();
//         int temp[n];
//         vector<int>ans;
//         for(int i=0;i<nums.size();i++){
//            temp[i]=nums[i];
//         }
//         sort(nums.begin(),nums.end());
//          int l=0,r=nums.size()-1;
//         while(l<r){
//             if(nums[l]+nums[r]==target){      
//                 break;
//             }
//             else if(nums[l]+nums[r]>target){
//                 r--;
//             }
//             else{
//                 l++;
//             }
//         }
//         for(int i=0;i<n;i++){
//             if(nums[l]==temp[i]){
//                 ans.push_back(i);
//             }
//             else if(nums[r]==temp[i]){
//                 ans.push_back(i);
//             }
//         }
        
//         return ans;
//     }
// };
// Efficient Approach Using Unordered Map

//  class Solution {
// public:
// vector<int> twoSum(vector<int>& nums, int target) {
//     int n=nums.size();
//     vector<int>ans;
//     unordered_map<int,int>umap;
//     for(int i=0;i<n;i++)
//     {
// 	    // If we find (target-nums[i]) in our map then it means that i and umap[target-nums[i]] these two are our answer.
//         if(umap.count(target-nums[i])){
//             ans.push_back(umap[target-nums[i]]);
//             ans.push_back(i);
//         }
//         umap[nums[i]]=i;
//     }
//     return ans;
//   }
// };