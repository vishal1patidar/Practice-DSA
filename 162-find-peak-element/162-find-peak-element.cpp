class Solution {
 public:
  int findPeakElement(std::vector<int>& nums) {
    int first = 0;
    int end = nums.size() - 1;

    while (first < end) {
      int mid = (first + end) / 2;
      if (nums[mid] > nums[mid + 1]) {
        end = mid;
      } else {
        first = mid + 1;
      }
    }
    
    return first;
  }
};