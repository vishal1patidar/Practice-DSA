// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int shortestUnSub(string s, string t) {
        int n = s.size(), m = t.size() ;
    vector< vector<int> > dp(n+1, vector<int>(m+1,INT_MAX)) ;
    for(int i=0 ; i<=n-1 ; i++)
        dp[i][m] = 1 ;
    for(int i=n-1 ; i>=0 ; i--){
        for(int j=m-1 ; j>=0 ; j--){
            int k = j ;
            while(k<m && s[i] != t[k])
                k++ ;
            if(k == m)
                dp[i][j] = 1 ;
            else
                dp[i][j] = min(dp[i+1][j],(dp[i+1][k+1] == INT_MAX ? INT_MAX : dp[i+1][k+1] + 1)) ;
        }
    }
    return dp[0][0] == INT_MAX ? -1 : dp[0][0] ;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        cin>>S>>T;

        Solution ob;
        cout << ob.shortestUnSub(S,T) << endl;
    }
    return 0;
}  // } Driver Code Ends