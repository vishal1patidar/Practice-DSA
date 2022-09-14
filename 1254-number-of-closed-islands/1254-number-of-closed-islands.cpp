class Solution {
public:
	void dfs(vector<vector<int>>& grid,int i,int j,int r,int c){
		if(i<0 || j<0 || i>=r ||j>=c || grid[i][j]==1){
			return;
		}
		grid[i][j]=1;
		dfs(grid,i+1,j,r,c);
		dfs(grid,i-1,j,r,c);
		dfs(grid,i,j+1,r,c);
		dfs(grid,i,j-1,r,c);



	}
	int closedIsland(vector<vector<int>>& grid) {
		int r=grid.size(),c=grid[0].size(),count=0;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if((i==0 || j==0 || i==(r-1)||j==(c-1))&&grid[i][j]==0){
					dfs(grid,i,j,r,c);
				}
			}
		}

		for(int i=1;i<r-1;i++){
			for(int j=1;j<c-1;j++){
				if(grid[i][j]==0){
					count++;
					dfs(grid,i,j,r,c);
				}
			}
		}
		return count;

	}
};