// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
 public:
   long long minTime(int arr[], int n, int k)
   {
       // code here
       // return minimum time
       long long sum=0,res=-1;
       int low=*max_element(arr,arr+n);
       long long high=accumulate(arr,arr+n,sum);
       while(low<=high)
       {
           long long mid=low+(high-low)/2;
           long long s=0,count=1;
           for(int i=0;i<n;i++)
           {
               s+=arr[i];
               if(s>mid)
               {
                   count++;
                   i=i-1;
                   s=0;
               }
           }
           
            if(count<=k)
          {
           res=mid;
           high=mid-1;
          }
          else
          low=mid+1;
       }
      return res;
   }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends