class Solution {
    vector<int> arr, idx;
public:
    Solution(vector<int> nums) {
        srand(time(NULL));
        arr.resize(nums.size());
        idx.resize(nums.size());
        for (int i=0;i<nums.size();i++){
            arr[i] = nums[i];
            idx[i] = nums[i];
        }
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        for (int i=0;i<arr.size();i++)
            arr[i] = idx[i];
        return arr;    
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
         int i,j;
         for (i = arr.size() - 1; i > 0; i--) {
            j = rand() % (i + 1);
            swap(arr[i], arr[j]);
         }
         return arr;    
    }
};