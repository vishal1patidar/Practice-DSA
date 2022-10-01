// class Solution {
// public:
//     int solve(int n){
//         if(n==0){
//             return 0;
//         }
//         if(n<0)return INT_MAX-1;
        
//         int mini=INT_MAX;
        
//         for(int i=1;i*i<=n;i++){
//            mini=min(mini,solve(n-(i*i))+1) ;
//         }
        
//         return mini;
//     }
    
//     int numSquares(int n) {        
//         return solve(n);
//     }
// };


class Solution {
public:
    int solve(int n,unordered_map<int,int>& dp){
        if(dp.find(n)!=dp.end())return dp[n];
        if(n<0)return dp[n]=INT_MAX-1;
        
        int mini=INT_MAX;
        
        for(int i=1;i*i<=n;i++){
           mini=min(mini,solve(n-(i*i),dp)+1) ;
        }
        
        return dp[n]=mini;
    }
    
    int numSquares(int n) {      
        unordered_map<int,int> dp;
        dp[0]=0;
        return solve(n,dp);
    }
};