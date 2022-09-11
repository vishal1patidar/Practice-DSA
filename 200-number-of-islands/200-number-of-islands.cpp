class Solution {
public:
    bool ok(int r, int c, int n, int m){
        return (r>=0 && r<n && c>=0 && c<m);
    }
    void dfs(int r, int c, int n, int m, vector<vector<char>>& grid){
        if(!ok(r,c,n,m) || grid[r][c]=='0') return;
        grid[r][c]='0';
        dfs(r+1,c,n,m,grid);
        dfs(r-1,c,n,m,grid);
        dfs(r,c+1,n,m,grid);
        dfs(r,c-1,n,m,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        int n=(int)grid.size(), m=(int)grid[0].size();
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]=='1'){
                    ++islands;
                    dfs(i,j,n,m,grid);
                }
            }
        }
        return islands;
    }
};