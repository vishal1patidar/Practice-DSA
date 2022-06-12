// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
bool ispali(string s){
    int i = 0;
    int j = s.size()-1;
    while(i<=j){
        if(s[i] != s[j]){
            return false;
        }
        i++;j--;
    }return true;
}
    int minChar(string str){
        //Write your code here
        int i = 0;
        int count = 0;
        while(i<str.size()){
            if(ispali(str.substr(0,i+1))){
                count = max(count,i+1);
            }
            i++;
        }
        return str.size()-count;
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
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends