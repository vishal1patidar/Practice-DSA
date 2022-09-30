class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>h((amount+1), INT_MAX-1);
        h[0] = 0;
        for(int i = 0; i < h.size(); i++)
        {
            for(int j = 0; j < coins.size(); j++)
            {
                if(i >= coins[j]) h[i] = min(h[i], 1 + h[i-coins[j]]);
            }
        }
        return (h[h.size()-1] < INT_MAX - 1)?h[h.size()-1]:-1; 
    }
};