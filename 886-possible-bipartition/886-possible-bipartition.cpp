class Solution {
public:
    vector<bool> visited;
    vector<bool> color;
    bool bipartition = true;
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        color.assign(n+1, false);
        visited.assign(n+1, false);
        
        vector<vector<int>> graph (n+1, vector<int>());
        for (vector<int> dislike : dislikes) {
            graph[dislike[0]].push_back(dislike[1]);
            graph[dislike[1]].push_back(dislike[0]);
        }
        
        for (int i=1; i<=n; i++) {
            traverse(graph, i);
        }
        
        return bipartition;
    }
    
    void traverse(vector<vector<int>>& graph, int s) {
        if (!bipartition) return;
        
        visited[s] = true;
        
        for (int t : graph[s]) {
            if (!visited[t]) {
                color[t] = !color[s];
                traverse(graph, t);
            } else {
                if (color[t] == color[s]) {
                    bipartition = false;
                    return;
                }
            }
        }
    }
};