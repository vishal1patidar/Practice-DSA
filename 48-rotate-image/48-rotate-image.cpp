class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n = m.size();
        for (int i = 0; i < n; ++i) {
            reverse(m[i].begin(), m[i].end());
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n-i; ++j) {
                swap(m[i][j], m[n-1-j][n-1-i]);
            }
        }
    }
};