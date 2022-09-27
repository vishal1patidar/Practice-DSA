class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    //int minsum = INT_MAX; // useless, becase we can just return dp[last][last] 
    int x = grid.size();
    int y = grid[0].size();
	// using dp (dynamic programming) as name because it uses the concept to solve the problem.
	// each dp[i][j] means the minimun path sum from up or left to here.
	// generic definition for: dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]; // i ==0 || j ==0 cases are border cases.
    vector<vector<int>> dp(x, vector<int>(y, 0));
    int i = 0, j = 0;
    for(i = 0; i < x; ++i)
        for(j = 0; j < y; ++j)
        {
            if(i == 0 && j == 0)
                dp[i][j] = grid[0][0];
            else if(j == 0)
                dp[i][j] = dp[i-1][j]+ grid[i][j];
            else if(i == 0)
                dp[i][j] = dp[i][j-1]+ grid[i][j];
            else
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    return dp[x-1][y-1];
}
};