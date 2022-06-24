// { Driver Code Starts
// C++ implementation to convert a
// sentence into its equivalent
// mobile numeric keypad sequence
#include <bits/stdc++.h>
using namespace std;
string printSequence(string input);
// Driver function
int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
    {
        string s;
        getline(cin,s);
        cout<<printSequence(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string printSequence(string S)
{
unordered_map<char,string> mp;
   int cnt = 2;
   for(char i = 'A';i<='Z';i++)
   {
       if(i=='P' || i=='W')
       {
           // i+=3;
           // cnt++;
           // continue;
           int l=1;
           while(l<5)
           {
               string s="";
               int x = l;
               while(x--)
               {
                   s+=to_string(cnt);
               }
               mp[i]=s;
               l++;
               i++;
           }
           i--;
           cnt++;
       }
       else{
           int l=1;
           while(l<4)
           {
               string s="";
               int x = l;
               while(x--)
               {
                  s+=to_string(cnt);
               }
               mp[i]=s;
               l++;
               i++;
           }
           i--;
           cnt++;
       }
   }
   mp[' ']="0";
   
   
   for(int i=0;i<S.size();i++)
   {
       cout<<mp[S[i]];
   }
}