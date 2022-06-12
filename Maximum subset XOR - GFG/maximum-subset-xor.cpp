// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// Function to return maximum XOR subset in set[]

class Solution
{
    public:
    int maxSubarrayXOR(int arr[], int N)
    {
       if(N == 0) return 0;
int x = 0;
while(1)
{
  int y = *max_element(arr,arr+N);
  if(y == 0) return x;
  x = max(x,x^y);
  for(int i=0;i<N;i++)
  {
    arr[i] = min(arr[i],arr[i]^y);
  }
}
        //Your code here
    }
};

// { Driver Code Starts.
int main()
{

    int t,n,a[100004],k;
    scanf("%d",&t);
    while(t--)
    {
        //cin>>n;
       scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        Solution obj;
        printf("%d\n",obj.maxSubarrayXOR(a,n));
       // cout<<bin(a,0,n-1,k)<<endl;
    }
}  // } Driver Code Ends