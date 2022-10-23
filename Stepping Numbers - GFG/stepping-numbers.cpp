//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
private:

    void dfs(int curr, int lastDig, int& n, int& m, int& cnt) {
        if(lastDig < 0 || lastDig > 9) return;
        
        int newNum = curr*10 + lastDig;
        if(newNum > m) return;
        
        if(newNum >= n && newNum <= m) ++cnt;
        
        dfs(newNum, lastDig-1, n, m, cnt);
        dfs(newNum, lastDig+1, n, m, cnt);
        
        return;
        
    }

public:

    int steppingNumbers(int n, int m)
    {
        int cnt = 0;
        if(n == 0) ++cnt;
        for(int i=1; i<=9; ++i) {
            dfs(0, i, n, m, cnt);
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends