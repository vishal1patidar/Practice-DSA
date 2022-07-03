// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
   void solve(string &s,int i,int j,set<string> &word_set,vector<string> &str,string output)
{
   if(i>j)
   {
       str.push_back(output);
       return ;
   }
     string tr="";
     for(int k = i; k<=j;k++)
      {
          tr = tr+s[k];
          if(word_set.find(tr)!= word_set.end())
          {
              if(output.size()==0)
               solve(s,k+1,j,word_set,str,tr);
               else
               solve(s,k+1,j,word_set,str,output+" "+tr);
             
             
          }
      }
   
   
}
   vector<string> wordBreak(int n, vector<string>& wordDict, string s)
   {
       // code here
       vector<string> str;
       string output="";
       set < string > word_set(wordDict.begin(), wordDict.end());
       solve(s,0,s.size()-1,word_set,str,output);
       return str;
   }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends