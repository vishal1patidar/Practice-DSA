class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> orderMap;
        
        for (int i = 0; i < nums.size(); ++i) {
            ++orderMap[nums[i]];
        }
        
        int slow = 0, fast = 0, lastElement = -1, tmpValue;
        
        for (auto it = orderMap.begin(); it != orderMap.end(); ++it) {
            tmpValue = it->second * it->first;;
            if (lastElement == it->first - 1) {
                tmpValue += slow;
            } else {
                tmpValue += max(slow, fast);
            }
            
            slow = max(slow, fast);
            fast = tmpValue;
            lastElement = it->first;
        }
        
        return max(slow, fast);
    }
};