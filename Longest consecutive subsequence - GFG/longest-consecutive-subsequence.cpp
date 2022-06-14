// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
          // sort the array 
     sort(arr,arr+N);
     
     // insert in set to remove duplicate 
     set<int>s;
     for(int i=0; i<N; i++)
     {
         s.insert(arr[i]);
     }
     // Insert element in vector 
     vector<int>ans;
     for(auto x :s)
     {
         ans.push_back(x);
     }
     int count=1;
     int cnt=0;
     
     // check longest consecutive subsequence 
     for(int i=0; i<ans.size(); i++)
     {
         if((ans[i]+1)==ans[i+1])
        {
           count++;
        }
         else
         {
             if(cnt<count)
             {
                 cnt=count;
             }
             count=1;
         }
     }
     return cnt;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends