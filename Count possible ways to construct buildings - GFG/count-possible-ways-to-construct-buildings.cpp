// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
   
class Solution{
public:
long long int f(int i, int N, vector<int>& dp){
    if(i > N)
    return 1;
    if(dp[i] != -1) return dp[i];
    int take =  f(i + 2,N,dp);
    int nottake = f(i + 1,N,dp);
    
    return dp[i] =  (take+nottake)%1000000007;
}
int TotalWays(int N)
{
    int i = 1;
    vector<int> dp(N+1,-1);
    long long int solve = f(i,N,dp);
    return (solve*solve)%1000000007;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends