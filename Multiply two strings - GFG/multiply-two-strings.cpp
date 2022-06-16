// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       int sign=0;
     
  int x=0;
  int y=0;
  
  if(s1[0]=='-'){
      s1.erase(0,1);
      x=1;
  }
  
  if(s2[0]=='-'){
      s2.erase(0,1);
      y=1;
  }
  sign=x^y;

      string ans="";
      for(int i=0;i<s1.size()+s2.size();i++){
          ans.push_back('0');
      }
      reverse(s1.begin(),s1.end());
      reverse(s2.begin(),s2.end());
      
      for(int i=0;i<s1.size();i++){
          int k=i; int c=0;
          for(int j=0;j<s2.size();j++){
              int m=(s1[i]-'0')*(s2[j]-'0') + ans[k]-'0' +  c;
              char ch=(m%10)+'0';
              ans[k++]=ch;
              c=m/10;
          }
          if(c!=0){
            ans[k++]=(c+'0');  
          }
      }
      
      reverse(ans.begin(),ans.end());
      int i=0;
      while(ans[i]=='0'){
          i++;
      }
       
    ans= ans.substr(i);
    
    if(ans.size()==0)return "0";
    
        if(sign==1){
            ans='-'+ans;
        }
       
        return ans;
    }

};

// { Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}  // } Driver Code Ends