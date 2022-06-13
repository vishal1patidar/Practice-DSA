// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  static bool comp(pair<int,int>p1,pair<int,int>p2)
{
   return(p1.second>p2.second);
}
 public:
    // Function to find majority element in the array
   // a: input array
   // size: size of input array
   int majorityElement(int a[], int n)
   {
      unordered_map<int,int>mp;
  for(int i=0;i<n;i++)
  {
      mp[a[i]]++;
  }
vector<pair<int,int>>vec(mp.begin(),mp.end());
sort(vec.begin(),vec.end(),comp);
auto it=vec.begin();
 if(it->second<=n/2) return -1;
  return it->first;
       
   }
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends