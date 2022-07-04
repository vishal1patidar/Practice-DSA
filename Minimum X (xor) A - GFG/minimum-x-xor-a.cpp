// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        int noOfBitsInB = 0;
        for(int i=30; i>=0; i--){
            if(((b>>i)&1) != 0){
                noOfBitsInB += 1;
            }
        }
        int cnt = noOfBitsInB;
        // System.out.println(noOfBitsInB);
        int x = 0;
        for(int i=30; i>=0 && cnt>0; i--){
            if(((a>>i)&1) != 0){
                x = (x^(1<<i));
                cnt -= 1;
            }
        }
        // System.out.println(x);
        for(int i=0; i<31 && cnt>0; i++){
            if(((x>>i)&1) == 0){
                x = (x^(1<<i));
                cnt -= 1;
            }
        }
        return x;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends