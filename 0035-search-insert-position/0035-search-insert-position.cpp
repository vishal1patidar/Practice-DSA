class Solution {
public:
    int searchInsert(vector<int>& arr, int t) {
        return lower_bound(arr.begin(), arr.end(), t) - arr.begin();
    }
};