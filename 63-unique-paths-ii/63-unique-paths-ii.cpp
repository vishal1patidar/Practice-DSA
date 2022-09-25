class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        for (int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {   // if meet a obstacle, change its value to 0
                    obstacleGrid[i][j] = 0;  
                    continue;
                }
                if (i - 1 >= 0 && j - 1 >= 0) {
                    obstacleGrid[i][j] = obstacleGrid[i][j - 1] + obstacleGrid[i - 1][j];
                } else if (i - 1 >= 0) {
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j];
                } else if (j - 1 >= 0) {
                    obstacleGrid[i][j] = obstacleGrid[i][j - 1];
                } else {
                    obstacleGrid[i][j] = 1;
                }
            }
        }
        return obstacleGrid[m - 1][n - 1];
    }
};