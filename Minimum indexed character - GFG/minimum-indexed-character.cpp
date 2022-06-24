// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find the minimum indexed character.
    int minIndexChar(string s , string p )
    {
        int m[26] = {0};
       for(int i=0; i<p.size(); i++) {
           m[p[i] -'a']++;
       }
       for(int i=0; i<s.size(); i++) {
           if(m[s[i]- 'a'] > 0) {
               return i;
           }
       }
       return -1;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
    cin>>t;
    while(t--)
    {
        string str;
        string patt;
        cin>>str;
        cin>>patt;
        Solution obj;
        cout<<obj.minIndexChar(str, patt)<<endl;
    }
	return 0;
}
  // } Driver Code Ends