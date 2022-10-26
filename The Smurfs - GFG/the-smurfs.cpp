//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findMin(int n, char a[]){
        // code here
        int cntR = 0, cntG = 0, cntB = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 'R') cntR++;
            else if (a[i] == 'B') cntB++;
            else cntG++;
        }
        if (cntR % 2 == 0 && cntB % 2 == 0 && cntG % 2 == 0)
            return 2;
        if (cntR % 2 == 1 && cntB % 2 == 1 && cntG % 2 == 1)
            return 2;
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        cout<<ob.findMin(n, a)<<"\n";
    }
    return 0;
}
// } Driver Code Ends