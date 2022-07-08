// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// 




class Solution{
public:
  pair<int,string> recur(int p[],int n,int low,int high, pair<int,string> dp[27][27])
  {
      // base as MCM when we return 0 and string is char at that index
      if(low==high)
      {
          char ch='A'+low;// char at index
          string s="";
          s+=ch;
          return {0,s};
      }
      // now memozization part checking if that sub array we already cal
      if(dp[low][high].first!=-1)
      {
          return dp[low][high];
      }
      pair<int,string> res;
       res.first=INT_MAX;// as we have to minimize this as MCM
      
      // now trying all possiblity btw low to high and see where we can get mini result
      for(int i=low;i<high;i++)
      {
          auto left=recur(p,n,low,i,dp); // taking left part
          auto right=recur(p,n,i+1,high,dp); // taking right part
          
          int tempRes=left.first+right.first+(p[low]*p[i+1]*p[high+1]);//same as MCM
          if(res.first>tempRes)
          {
              res.first=tempRes;
              res.second="("+left.second+right.second+")";
          }
      }
      
      return dp[low][high]=res;
      
  }
   string matrixChainOrder(int p[], int n){
       // code here
       // this is just slight modification of MCM
       // in MCM we have to only return  min mul here we have to return that seq of bracket in string
       // so for that we will take cnt as well string cnt contains mini mul and string contain ans at that cnt
         
         pair<int,string> dp[27][27];
         pair<int,string> empty;empty.first=-1;
         // intilizing with empty and cnt is -1 for all intially
         
         for(int i=0;i<=n;i++)
         {
             for(int j=0;j<=n;j++)
             dp[i][j]=empty;
         }
         int low=0,high=n-2;// here from where we start putting bracket is low and upto high we can put 
         
         return recur(p,n,low,high,dp).second;
   }
};
// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends