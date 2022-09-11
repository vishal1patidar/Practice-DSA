class Solution {
public:
    void dfs(vector<vector<int>> &grid, int i, int j, int time){
        int m = grid.size();
        int n = grid[0].size();
        // base case
        if(i>=m || j>=n || i<0 || j<0 || grid[i][j]==0 || 
            (grid[i][j]>1 && grid[i][j]<time)) return;
        
        grid[i][j] = time;
        dfs(grid, i+1, j, time+1);
        dfs(grid, i-1, j, time+1);
        dfs(grid, i, j+1, time+1);
        dfs(grid, i, j-1, time+1);
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int time=2;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 2)
                dfs(grid, i, j, time);
            }
        }
        
        for(auto i: grid){
            for(auto j: i){
                if(j==1) return -1;
                time = max(time, j);
            }
        }
        return time-2;
    }

};