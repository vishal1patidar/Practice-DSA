class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int mn , ans; 
        mn = INT_MAX;
        ans = 0;
        for(int i = n-1; i>=0; i--)
        {
            ans = max ( ans, i+values[i]-mn);
            mn = min(mn, i-values[i]);
        }
        return ans;
    }
};