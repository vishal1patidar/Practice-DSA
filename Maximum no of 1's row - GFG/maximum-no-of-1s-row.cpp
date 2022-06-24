// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        int maxOnes (vector <vector <int>> &Mat, int N, int M)
        {
            int ans =INT_MIN;
            int res=-1;
            for(int i=0;i<N;i++){
                
                map<int,int> mp;
                for(auto a:Mat[i]){
                    mp[a]++;
                }
                if(mp[1]>ans){
                    ans=mp[1];
                    res=i;
                }
            }
            return res;
        }
};

// { Driver Code Starts.

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;        
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}  // } Driver Code Ends