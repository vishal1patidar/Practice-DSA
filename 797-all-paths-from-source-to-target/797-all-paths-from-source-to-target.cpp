class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        

        vector<vector<int>> res;
        vector<int> path;
        path.push_back(0);
        dfs(graph, 0, path, res);
        return res;


    }
    void dfs(vector<vector<int>>& graph, int cur, vector<int>& path, vector<vector<int>>& res) {
        if (cur == graph.size() - 1) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < graph[cur].size(); i++) {
            path.push_back(graph[cur][i]);
            dfs(graph, graph[cur][i], path, res);
            path.pop_back();
        }
    }
    

};