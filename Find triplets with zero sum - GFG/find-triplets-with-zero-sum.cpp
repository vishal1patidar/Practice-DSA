// { Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

 // } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
       vector<int> v(n);
        for(int i=0;i<n;i++)
        v[i]=arr[i];
        
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
            int lo=i+1,hi=n-1,sum=0-(v[i]);
            while(lo<hi)
            {
                if(v[lo]+v[hi]==sum)
                {
                  return true;
                }
                else if(v[lo]+v[hi]>sum) hi--;
                else  lo++;
            }
        }
        return false;
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}  // } Driver Code Ends