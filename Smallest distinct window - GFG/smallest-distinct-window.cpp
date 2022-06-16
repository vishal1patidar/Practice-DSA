// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        unordered_map<char, int> mp;
        for(auto &e : str){
            mp[e] = 0;
        }
        int cnt = 0;
        int idx = 0;
        int i = 0;
        int ans = INT_MAX;
        while(i < str.size()){
            if(mp[str[i]] == 0){
                mp[str[i]]++;
                cnt++;
                if(cnt == mp.size()){
                    ans = min(ans, i - idx + 1);
                }
                i++;
            }
            else{
                mp[str[i]]++;
                while(mp[str[idx]] > 1){
                    mp[str[idx]]--;
                    idx++;
                }
                if(cnt == mp.size())
                    ans = min(ans, i - idx + 1);
                i++;
            }
        }
        return ans;   
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends