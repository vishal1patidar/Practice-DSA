class Solution {
public:
bool isvalid(int i,int j,int n,int m,vector<vector<int>>& grid)
    {
        if(i>=0&&i<n&&j>=0&&j<m&&grid[i][j]==1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void dfs(int i,int j,vector<vector<int>>& grid,int n,int m,int &area)
    {
        grid[i][j]=0;
        area++;
        if(isvalid(i+1,j,n,m,grid))
        {
            dfs(i+1,j,grid,n,m,area);
        }
         if(isvalid(i-1,j,n,m,grid))
        {
            dfs(i-1,j,grid,n,m,area);
        }
         if(isvalid(i,j+1,n,m,grid))
        {
            dfs(i,j+1,grid,n,m,area);
        }
         if(isvalid(i,j-1,n,m,grid))
        {
            dfs(i,j-1,grid,n,m,area);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int area=0;
                if(grid[i][j]==1)
                {
                    dfs(i,j,grid,n,m,area);
                    ans=max(area,ans);
                }
            }
        }
        return ans;
    }
};