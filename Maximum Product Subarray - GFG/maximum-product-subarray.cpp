// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    if(n == 1) {
	        return arr[0];
	    }
	    long long int max = 1, newmax;
	    for(int i = 0; i < n; i++) {
	        if(arr[i] == 0) {
	            continue;
	        }
	        newmax = 1;
	        for(int j = i; j < n; j++) {
	           if(arr[j] == 0) {
	               break;
	           }
	            newmax *= arr[j];
	            if(newmax > max) {
	                max = newmax;
	            }
	        }
	    }
	    return max;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends