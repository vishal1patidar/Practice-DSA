class Solution {
public:
     int maxProfit(vector<int>& prices) {
        int res = 0, p = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] - prices[p] > res) {
                res = prices[i] - prices[p];
            } else {
                p = prices[p] < prices[i] ? p : i;
            }
        }
        return res;
    }
};