// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
    for(int i=0;i<n;i++)
    sum+=arr[i];
    vector<vector<int>>v(n,vector<int>(sum+1,0));
       for(int i=0;i<n;i++)
       v[i][0]=1;
       for(int i=1;i<=sum;i++)
       {
           if(i==arr[0])
           v[0][i]=1;
           else
           v[0][i]=0;
       }
       for(int i=1;i<n;i++)
       {
           for(int j=1;j<=sum;j++)
           {   int x=0;
               if(j>=arr[i])
               x=v[i-1][j-arr[i]];
               int y=v[i-1][j];
               if(x+y>0)
               v[i][j]=1;
               else
               v[i][j]=0;
           }
       }
    int ans=sum;
    for(int i=0;i<=sum/2;i++)
    {
        if(v[n-1][i])
        {
            ans=min(ans,abs(sum-2*i));
        }
    }
    return ans;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends