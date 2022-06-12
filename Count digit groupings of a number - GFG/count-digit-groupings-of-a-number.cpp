// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    
	public:
    int helper(int ind,int prevSum,string &str,int n,vector<vector<int>> &dp){
    if(ind == n) return (1);
    if(dp[ind][prevSum] != -1) return dp[ind][prevSum];
    
    int cnt = 0;
    int currSum = 0;
    for(int i = ind; i < n; i++){
        currSum += str[i] - '0';
        if(currSum >= prevSum){
            cnt += helper(i+1,currSum,str,n,dp);
        }
    }
    return (dp[ind][prevSum] = cnt);
}

    int TotalCount(string str){
    int n = str.length();
    int sum = accumulate(str.begin(),str.end(),0) - '0'*n;
    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
    return helper(0,0,str,n,dp);
}


};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends