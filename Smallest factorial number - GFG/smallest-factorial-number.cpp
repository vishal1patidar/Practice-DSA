// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        int findNum(int n)
        {
        //complete the function here
        int ans=0,cnt, s,e,m;
       
       s = 5;
       e = n*5;
       
       while(s<=e){
           m = s+(e-s)/2;
           cnt = 0;
           
           for(int i=5;i<=m;i*=5)
               cnt += m/i;
           
           if(cnt<n)
               s= m+1;
           else{
               ans = m;
               e = m-1;
           }
       }
       
       
       return ans;
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends