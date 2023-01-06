


class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // greedy
        // buy the cheapest ice cream bar first
        int ans = 0;
        sort(costs.begin(), costs.end());
        for (auto c : costs) {
            // if we don't have enough coins,
            // then break it
            if (coins - c < 0) break;
            // buy one
            ans += 1;
            // update coins
            coins -= c;
        }
        return ans;
    }
};