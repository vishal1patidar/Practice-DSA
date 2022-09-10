class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size()- 1;
        
        vector<int> ans;
        
        while(start < end){
            if(numbers[start] + numbers[end] == target){
                ans.push_back(start + 1);
                ans.push_back(end + 1);
                break;
            }
            else if( numbers[start] + numbers[end] > target){
                end--;
            }
            else{
                start++;
            }
        }
        return ans;
    }
};