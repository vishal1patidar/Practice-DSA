// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    int i, first, second;

	    // There should be at least two elements
	    if (n < 2) {
	        return -1;
	    }

	    first = second = INT_MIN;
	    for (i = 0; i < n; i++) {

	        // If current element is greater
	        // than first then update both
	        // first and second
	        if (arr[i] > first) {
	            second = first;
	            first = arr[i];
	        }

	        // If arr[i] is in between first
	        // and second then update second
	        else if (arr[i] > second && arr[i] != first) {
	            second = arr[i];
	        }
	    }
	    if (second == INT_MIN)
	        return -1;
	    else
	        return second;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends