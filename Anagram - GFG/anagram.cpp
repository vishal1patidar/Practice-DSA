// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
      int m = a.length();
     int n = b.length();
     if(m!= n)
     {
         return false;
     }
     unordered_map<char,int>mp1;
     for(int i=0;i<m;i++)
     {
         mp1[a[i]]++;
     }
    
     for(int i=0;i<n;i++)
     {
         if(mp1.find(b[i]) != mp1.end())
         {
             mp1[b[i]]--;
             if(mp1[b[i]] == 0)
             {
                 mp1.erase(b[i]);
             }
         }
     }
     if(mp1.size() == 0)
     {
         return true;
     }
     return false;
        
    }

};

// { Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
  // } Driver Code Ends