// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            unordered_set<char>s;
           for(auto &ch : B)
           {
               s.insert(ch);
           }
          
         set<char>ans; 
          
           for(auto &ch : A)
           {
               auto it=s.find(ch);
               if(it==s.end()){
                   ans.insert(ch);
               }
           }
           
           unordered_set<char>st;
           for(auto &ch : A)
           {
               st.insert(ch);
           }
           
           for(auto &ch : B){
               auto it=st.find(ch);
               if(it==s.end())
               {
                   ans.insert(ch);
               }
           }
           
           string str="";
           for(auto &ch : ans)
           {
               str.push_back(ch);
           }
           
           
           return str.empty() ? "-1" : str;
       
        
        }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends