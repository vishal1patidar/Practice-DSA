//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        int open=0,close=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') open++;
            else if(s[i]==')')close++;
            if(close==open) ans=max(ans,close+open);
            else if(close>open) open=close=0;
        }
        close=open=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='(') open++;
            else close++;
            if(close==open) ans=max(ans,open+close);
            else if(open>close) open=close=0;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends