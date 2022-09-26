class Solution {
public:
    int helper(int row , int col , vector<vector<int>>& matrix , vector<vector<int>>& dp){
        if(col < 0 || col > matrix.size()-1) return INT_MAX;
        if(row == matrix.size()-1) return matrix[row][col];
        if(dp[row][col] != -1) return dp[row][col];
        
        int left = helper(row + 1 , col - 1 , matrix , dp );
        int bottom = helper(row + 1 , col  , matrix , dp );
        int right = helper(row + 1 , col + 1 , matrix , dp );
        dp[row][col] = matrix[row][col] + min(left , min(bottom , right));
        return dp[row][col];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size() , ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n , -1));
        for(int i = 0 ; i<n ;i++) ans = min(ans , helper(0 , i , matrix , dp));
        return ans;
    }
};