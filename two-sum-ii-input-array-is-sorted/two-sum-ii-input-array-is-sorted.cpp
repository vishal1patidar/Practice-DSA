class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size() - 1;
        
        while(start < end) {                      // 2 - Pointer approach
            
            if(numbers[start] + numbers[end] > target)
                end--;
            
            else if(numbers[start] + numbers[end] < target)
                start++;
            
            else
                return {start + 1, end + 1};  // numbers[start] + numbers[end] == target
        }
        return {};
    }
};