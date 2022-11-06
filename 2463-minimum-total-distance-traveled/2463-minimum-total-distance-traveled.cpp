class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        //                #repair #cost
        vector<unordered_map<int, long long>> dp;
        
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        const int M = int(robot.size());
        const int N = int(factory.size());
        dp.resize(N);
        
        auto AddToMap = [&](int idx, int k, long long elt) {
//            printf("AddToMap(%d, %d, %lld)\n", idx, k, elt);
            unordered_map<int, long long>& m = dp[idx];
            if (m.count(k) < 1) {
                m[k] = elt;
            } else {
                m[k] = min(m[k], elt);
            }
        };
        
        for (int i=0; i<N; i++) {
//            printf("i=%d\n", i);
            long long prev_cost = 0;
            if (i > 0) {
                const unordered_map<int, long long>& prev = dp[i-1];
                for (const auto& pp : prev) {
//                    printf("pp=(%d,%lld)\n", pp.first, pp.second);
                    long long cand = pp.second;
                    AddToMap(i, pp.first, cand);
                    for (int rep = pp.first; rep < pp.first + factory[i][1]; rep++) { // How many do I repair?
                        if (rep < M) {
                            cand += abs(robot[rep] - factory[i][0]);
                            AddToMap(i, rep+1, cand);
                        }
                    }
                }
            } else {
                long long cand = 0;
                AddToMap(i, 0, cand);
                for (int rep=0; rep<factory[i][1]; rep++) {
                    cand += abs(robot[rep] - factory[i][0]);
                    AddToMap(i, rep+1, cand);
                }
            }
        }
        
        return dp.back()[robot.size()];
    }
};