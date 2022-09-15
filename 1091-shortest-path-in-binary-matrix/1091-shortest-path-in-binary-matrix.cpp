class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1){
            return -1;
        }
        int n = grid.size();
        vector<pair<int,int>> adj = {{1,0}, {-1,0}, {0,1}, {0,-1}, {-1, 1}, {1, -1}, {1, 1}, {-1,-1}};
        vector<vector<int>> dp(n, vector<int>(n, 0));
        set<pair<int,int>> visited;
        queue<pair<int,int>> q;
        q.push({0,0});
        dp[0][0] = 1;
        
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            for(int i = 0; i < 8; i++){
                int x = p.first + adj[i].first;
                int y = p.second + adj[i].second;
                if(x < 0 or y < 0 or x>= n or y >= n){
                    continue;
                }else{
                    if(visited.find({x,y}) != visited.end()){
                        continue;
                    }else{
                        visited.insert({x,y});
                    }
                    if(grid[x][y] == 1){
                        continue;
                    }else{
                        if(dp[x][y] == 0){
                            dp[x][y] = 1 + dp[p.first][p.second];
                        }
                        q.push({x,y});
                    }
                }
            }            
        }
        return dp[n-1][n-1] == 0 ? -1 : dp[n-1][n-1];
    }
 
};