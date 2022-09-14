class Solution {
public:

    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), ans = -1;
        
        queue<pair<int,int>> q;
        vector<pair<int,int>> adj = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        set<pair<int,int>> visited;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                }
            }
        }
        
        while(!q.empty()){
            pair<int,int> p =  q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int x = p.first + adj[i].first;
                int y = p.second + adj[i].second;
                if(x < 0 or y < 0 or x>= n or y >= n){
                    continue;
                }else{
                    /*Check if already visited the cell {x, y}*/
                    if(visited.find({x, y}) != visited.end()){
                        continue;
                    }else{
                        visited.insert({x, y});
                    }
                    if(grid[x][y] == 1){
                        q.push({x, y});
                    }else{
                        grid[x][y] = 1;
                        q.push({x,y});
                        /*
                        dp[p.f][p.s] is the adj cell where we have the distance between that cell and the nearest land
                        */
                        dp[x][y] = 1 + dp[p.first][p.second]; //The current cell plus 1 
                        ans = max(dp[x][y], ans);
                    }
                }
            }
        }
        return ans;
    }
};