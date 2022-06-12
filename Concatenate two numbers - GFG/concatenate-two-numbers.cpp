// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long countPairs(int n, int x, vector<int> num){
    unordered_map<string,int> m ;
    for(auto &x: num)
        m[to_string(x)]++ ;
    long long ans = 0 ;
    string left, right = to_string(x) ;
    
    while(right.size()){
        if(left == right)
            ans += m[left]*(m[left]-1) ;
        else
            ans += m[left]*m[right] ;
        
        left += right[0] ;
        right = right.substr(1) ;
    }
    
    return ans ;
}
}; 

// { Driver Code Starts.
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int N,X;
        cin>>N>>X;
        vector<int> numbers(N);
        for(int i=0;i<N;i++)
            cin>>numbers[i];
        Solution ob;
        long long ans = ob.countPairs(N, X, numbers);
        cout<<ans<<endl;
        
    }

    return 0; 
}  // } Driver Code Ends