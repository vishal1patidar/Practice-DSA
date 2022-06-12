// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++
class Solution{
    public:
   bool match(string wild, string pattern)
   {
       // code here
       int i=0,j=0;
       int n=wild.length(),m=pattern.length();
       for(int x=0;x<n-1;x++){
           if(wild[x]=='*' && (wild[x+1] =='*' || wild[x+1]=='?')){
               n--;
               wild.erase(x+1,1);
           }
       }
       while(wild[i]!='*' && (i<n && j<m)){
           if(wild[i]==pattern[j] || wild[i]=='?'){
               i++;
               j++;
           }
           else{
               return false;
           }
       }
       if(j==m){
           return true;
       }
       while(wild[i]=='*' && (i<n && j<m)){
           i++;
           if(pattern[j]==pattern[j+1]){
               j++;
           }
           while(wild[i]!=pattern[j] && wild[i]!='?' && j<m){
               j++;
           }
           while(wild[i]==pattern[j] && j<m && i<n){
               i++;
               j++;
           }
       }
       if(i!=n && j==m){
           return false;
       }
       if(j!=m){
           return false;
       }
       return true;
   }


};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}  // } Driver Code Ends