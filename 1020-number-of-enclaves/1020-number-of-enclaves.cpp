class Solution {
public:
	int dfs(vector<vector<int>>& grid,int i,int j,int r, int c){
		if(i<0 || i>=r || j<0 || j>=c || grid[i][j]==0){
			return 0;
		}
		grid[i][j]=0;
		return 1+dfs(grid,i+1,j,r,c)+dfs(grid,i-1,j,r,c)+dfs(grid,i,j+1,r,c)+dfs(grid,i,j-1,r,c);
	}
	int numEnclaves(vector<vector<int>>& grid) {
		int r=grid.size(),count=0,c=grid[0].size();
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(j==0 or i==0 or i==(r-1) or j==(c-1)){
					dfs(grid,i,j,r,c);
				}
			}
		}
		for(int i=1;i<r-1;i++){
			for(int j=1;j<c-1;j++){
				if(grid[i][j]==1){
					count++;
				}
			}
		}
		return count;
	}

};