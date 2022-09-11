class Solution {
    private:
    
    int f(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp){
        int n = triangle.size();
        if(i == n-1)return triangle[i][j];
        
        if(dp[i][j]!= -1)return dp[i][j];
        
        int down = triangle[i][j] + f(triangle, i+1, j, dp);
        int diag = triangle[i][j] + f(triangle, i+1, j+1, dp);
        
        return dp[i][j] = min(down, diag);
        
    }
public:
  
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return f(triangle, 0 , 0, dp); 
        
        //Bottom Up
        
//         vector<vector<int>> dp(n, vector<int>(n, 0));
//         for(int j=0;j<n;j++){
//             dp[n-1][j] = triangle[n-1][j];
//         }
        
//         for(int i = n-2; i>=0; i--){
//             for(int j = i; j>=0; j--){
//                 int down = triangle[i][j] + dp[i+1][j];
//                 int diag = triangle[i][j] + dp[i+1][j+1];

//                 dp[i][j] = min(down, diag);
//             }
//         }
//         return dp[0][0]; 
        
        
         // Space Optimization
        // TC = O(N*N)
        // SC = O(N)    
        
       vector<int>next_row(n, 0);
        for(int j=0;j<n;j++){
            next_row[j] = triangle[n-1][j];
        }
        
        for(int i = n-2; i>=0; i--){
             vector<int>curr_row(i+1);
            for(int j = i; j>=0; j--){
                int down = triangle[i][j] + next_row[j];
                int diag = triangle[i][j] + next_row[j+1];

                curr_row[j] = min(down, diag);
            }
            next_row = curr_row;
        }
        return next_row[0]; 
        
        
    }
};