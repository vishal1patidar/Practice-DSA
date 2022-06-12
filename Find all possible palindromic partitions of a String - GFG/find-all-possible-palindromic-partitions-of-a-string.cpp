// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    bool isPalindrome(string x){
        
        int n = x.size();
        
        for(int i=0; i<x.size(); i++){
            if(x[i] != x[n-i-1]) return false;
        }
        return true;
        
    }
  
    void solve(string &s, vector<vector<string>> &ans, vector<string> &tempAns){
        
        if(s.size() == 0){
            ans.push_back(tempAns);
            return;
        }
        
        string temp = "";
        
        for(int i=0; i<s.size(); i++){
            temp += s[i];
            
            if(isPalindrome(temp)){
                
                tempAns.push_back(temp);
                string tt = s.substr(i+1);
                solve(tt, ans, tempAns);
                tempAns.pop_back();
                
            }
        }
        
    }
  
    vector<vector<string>> allPalindromicPerms(string s) {
        
        vector<vector<string>> ans;
        vector<string> tempAns;
        
        solve(s, ans, tempAns);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends