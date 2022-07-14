// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}// } Driver Code Ends


string firstRepChar(string s)
{
    vector<char>v(26);
   string ans="";
   for(int i=0;i<s.size();i++){
       v[s[i]-'a']++;
       if(v[s[i]-'a']>1){
           return ans+=s[i];
       }
   }
   return "-1";
}