class Solution {
public:
    vector<pair<int, int>> moves = { {1,0}, {-1,0}, {0,1}, {0,-1} };
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
	    int row = grid2.size();
        int col = grid2[0].size();
        vector<vector<int>> visited(row, vector<int>(col, 0));
 
        int cnt = 0;
        for(int i=0; i<row; i++)
        {
	        for(int j=0; j<col; j++)
	        {
		        if(grid2[i][j]==1 && grid1[i][j]==1)
		        {   
                    //if the grid2[i][j]==grid1[i][j] -> we check if the grid1 contains all the land cells from grid 2
                    if (floodFill(grid2, i, j, grid2[i][j], 0, grid1,visited))
                        cnt++;
		        }
	        }
        }


        return cnt;
    }


    bool floodFill(vector<vector<int>>& matrix, const int r, const int c, const int initialValue, const int newValue, vector<vector<int>>& matrix2,vector<vector<int>>&visited)
    {
        //aux 
        
        queue < pair<int, int>>toVisit;
        toVisit.push({ r,c });
        visited[r][c] = 1;
        matrix[r][c] = newValue;
        bool isSubIsland = true;
        while (!toVisit.empty())
        {
            auto [iRow, iCol] = toVisit.front();
            toVisit.pop();
            for (auto [i, j] : moves)
            {
                int row = iRow + i;
                int col = iCol + j;
                if (row >= 0 && row < matrix.size() && col >= 0 && col < matrix[0].size() && matrix[row][col] == initialValue && visited[row][col] == 0)
                {
                    if (matrix2[row][col] != 1)
                        isSubIsland = false;    //if we found an element in the first grid that is 0 then we return false;
                    toVisit.push({ row,col });
                    visited[row][col] = 1;
                    matrix[row][col] = newValue;
                }
            }
        }
        return isSubIsland;
    }
};