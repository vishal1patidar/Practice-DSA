class Solution {
public:
     int nthUglyNumber(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        int c2(0),c3(0),c5(0);
        for(int i=1;i<=n;i++){
            // Formula of ugly number
            dp[i] = min({2*dp[c2],3*dp[c3],5*dp[c5]});
            if(2*dp[c2]==dp[i])
                c2++;
            if(3*dp[c3]==dp[i])
                c3++;
            if(5*dp[c5]==dp[i])
                c5++;
        }
        return dp[n-1];
        
        
    }
};