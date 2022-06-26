// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n1)
    {
        unordered_map<int,int> m;
       for(int i = 0; i<n1; i++){
           m[arr[i]]++;
       }
       int n = m.size();
       int ans = 0;
       m.clear();
       int i = 0, j = 0;
       while(i<n1){
           m[arr[i]]++;
           while(m.size() == n){
               ans+=(n1-i);
               m[arr[j]]--;
               if(m[arr[j]] == 0){
                   m.erase(arr[j]);
               }
               j++;
           }
           i++;
       }
       return ans;

    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends