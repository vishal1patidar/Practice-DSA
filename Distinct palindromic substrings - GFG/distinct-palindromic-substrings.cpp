// { Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
 public:
   unordered_set<string> m;
   int solve(string &s,int i,int j,vector<vector<int>> &a)
   {
       if(i>=j) return 1;
       if(a[i][j]!=-1) return a[i][j];
       if(s[i]!=s[j]) return a[i][j]=0;
       return a[i][j]=solve(s,i+1,j-1,a);
   }
   int palindromeSubStrs(string s) {
       // code here
       vector<vector<int>> a(s.size(),vector<int>(s.size(),-1));
       m.clear();
       for(int i=0;i<s.size();i++)
       {
           for(int j=i;j<s.size();j++)
           {
               if(solve(s,i,j,a))
               {
                   m.insert(s.substr(i,j-i+1));
               }
           }
       }
       return m.size();
   }
};

// { Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}
  // } Driver Code Ends