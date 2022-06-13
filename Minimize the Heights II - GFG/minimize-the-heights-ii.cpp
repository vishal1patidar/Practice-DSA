// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
if(n == 1) return 0;
       
       sort(arr, arr+n);
       
       int min_res = arr[0];
       int max_res = arr[n-1];
       int diff = max_res - min_res; 
       
       for(int i=1; i<n; i++){
           
           if(arr[i] - k < 0) continue;
           
           min_res = min(arr[0] + k, arr[i] - k);
           max_res = max(arr[i-1] + k, arr[n-1] - k);
           
           diff = min(diff, max_res - min_res);
       }
       
       return diff;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends