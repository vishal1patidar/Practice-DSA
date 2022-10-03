// Intuition
// For a group of continuous same characters,
// we need to delete all the group but leave only one character.


// Explanation
// For each group of continuous same characters,
// we need cost = sum_cost(group) - max_cost(group)


// Complexity
// Time O(N)
// Space O(1)


// C++:

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int res = 0, max_cost = 0, sum_cost = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (i > 0 && s[i] != s[i - 1]) {
                res += sum_cost - max_cost;
                sum_cost = max_cost = 0;
            }
            sum_cost += cost[i];
            max_cost = max(max_cost, cost[i]);
        }
        res += sum_cost - max_cost;
        return res;
    }
};
