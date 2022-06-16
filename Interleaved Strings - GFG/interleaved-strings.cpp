// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int dp[200][200];
    int f(string s1, string s2, string s3, int ind1, int ind2){
        if(ind1==-1 && ind2==-1) return 1;
        
        // cout<<ind1<<' '<<ind2<<'\n';
        int cur;
        if(ind1<0 && ind2>=0){
            if(s2.substr(0,ind2+1)==s3.substr(0,ind2+1)) return 1;
            else return 0;
        }
        
        if(ind2<0 && ind1>=0){
            if(s1.substr(0,ind1+1)==s3.substr(0,ind1+1)) return 1;
            else return 0;
        }
        
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        int op1=0,op2=0;
        
        cur=ind1+ind2+1;
        if(s3[cur]==s1[ind1]) op1=f(s1, s2, s3, ind1-1, ind2);
        if(s3[cur]==s2[ind2]) op2=f(s1, s2, s3, ind1, ind2-1);
        
        return dp[ind1][ind2]= (op1||op2);
        
        
        
    }
    bool isInterleave(string A, string B, string C) 
    {
        //Your code heref
        int n=A.size(), m=B.size();
        memset(dp, -1, sizeof(dp));
        return f(A, B, C, n-1, m-1);
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends