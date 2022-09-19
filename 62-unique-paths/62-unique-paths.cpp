class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,1));
        
     for(int i=1;i<m;i++)
     {
         for(int j=1;j<n;j++)
          {
              dp[i][j]=dp[i-1][j]+dp[i][j-1];
          }
     }
    return dp[m-1][n-1];
    }
};


// Approach 1 : recursive

// if(m==1||n==1)
//      return 1;
// return uniquePaths(m-1,n)+uniquePaths(m,n-1);
// Approach 2 : Dynamic programming

//  vector<vector<int>>dp(m,vector<int>(n,1));
        
//  for(int i=1;i<m;i++)
//  {
//      for(int j=1;j<n;j++)
//       {
//           dp[i][j]=dp[i-1][j]+dp[i][j-1];
//       }
//  }
// return dp[m-1][n-1];
// Approach 3 : space optimised dp

// vector<int>dp(n,1);
       
// for(int i=0;i<m-1;i++)
// {
// 	for(int j=1;j<n;j++)
//    {
// 	 dp[j]+=dp[j-1];
//    }
// }
//  return dp[n-1];
// Approach 4 : math combination

// int N=m+n-2;
// int r=m-1;
// long long int ans=1;
        
// for(int i=1;i<=r;i++)
// {
//       ans=(ans*(N-r+i)/i);
// }
// return (int)ans;