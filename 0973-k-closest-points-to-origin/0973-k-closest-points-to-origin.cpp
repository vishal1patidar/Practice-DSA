class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& P, int k) {
        auto euclidean = [](auto& p) { return p[0] * p[0] + p[1] * p[1]; };
        auto comp = [&](auto& a, auto& b) { return euclidean(a) > euclidean(b); };
        make_heap(begin(P), end(P), comp);
        
        vector<vector<int>> ans(k);
        for(int i = 0; i < k; i++) {
            ans[i] = P[0];
            pop_heap(begin(P), end(P), comp);
            P.pop_back();
        }
        return ans;
    }
};