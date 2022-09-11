class Solution {
public:
    int m = 0, n = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int area = 0, ans = 0;
        for(int i = 0; i < m; i++){
            for(int j  = 0; j < n; j++){
                if(grid[i][j] == 1){
                    area = explore(grid, i, j);
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
    int explore(vector<vector<int>>& g, int row, int col){
        if(row < 0 or col < 0 or row >= m or col >= n or g[row][col] == 0){
            return 0;
        }else{
            g[row][col] = 0;
            return 1 + explore(g, row+1, col) + explore(g, row-1, col) + 
                explore(g, row, col+1) + explore(g, row, col-1);
        }
    }
};