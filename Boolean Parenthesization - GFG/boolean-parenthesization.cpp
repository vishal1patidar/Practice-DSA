// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[201][201][2];
int solve(string &s, int i, int j,int istrue)
{
    if(i>j) return 0;
    if(i==j)
    {
        if(istrue) return s[i]=='T';
        else return s[i]=='F';
    }
    if(dp[i][j][istrue]!=-1)return dp[i][j][istrue];
    int ans=0;
    for(int k=i+1;k<=j-1;k=k+2)
    {
        int lt=solve(s,i,k-1,1);
        int lf=solve(s,i,k-1,0);
        int rt=solve(s,k+1,j,1);
        int rf=solve(s,k+1,j,0);
     if(s[k]=='&')
     {
         if(istrue) ans+=(lt*rt);
         else ans+=(lf*rt)+(lf*rf)+(lt*rf);
     }
     else if(s[k]=='|')
     {
         if(istrue) ans+=(lt*rt)+(lf*rt)+(lt*rf);
         else ans+=(lf*rf);
     }
     else if(s[k]=='^')
     {
        if(istrue) ans+=(lf*rt)+(lt*rf);
        else ans+=(lf*rf)+(lt*rt);
     }
    } 
    return dp[i][j][istrue]=(ans%1003);
}    
    int countWays(int N, string S){
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(S,0,N-1,1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends