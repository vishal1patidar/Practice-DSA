class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& P) {
        vector<vector<int>> G(N);
        vector<int> ans, indegree(N);
        for(auto& pre : P)
            G[pre[1]].push_back(pre[0]),
            indegree[pre[0]]++;
        
        function<void(int)> dfs = [&](int cur) {
            ans.push_back(cur);                     // take cur course & push it into ordering
            indegree[cur] = -1;                     // and mark it as visited
            for(auto nextCourse : G[cur])          
                if(--indegree[nextCourse] == 0)     // if there's a next course having 0 prequisite remaining,
                    dfs(nextCourse);                // then we can take it
        };
        for(int i = 0; i < N; i++)
            if(indegree[i] == 0)                    // we can start with courses having no prequisites
                dfs(i);
        
        if(size(ans) == N) return ans;
        return {};
    }
};