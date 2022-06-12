// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
   public:
   //Function to find minimum number of pages.
   int canBe(int arr[],int n,int m,int mid){
   int student=1;
   int page=0;
   for(int i=0;i<n;i++){
       if(page+arr[i]<=mid){
           page+=arr[i];
       }else{
           student++;
           if(student>m || arr[i]>mid){
               return false;
           }
           page=arr[i];
       }
   }
   return true;
}
   int findPages(int A[], int N, int M) 
   {
       //code here
       int start=0;
       int sum=0;
       int ans=-1;
       for(int i=0;i<N;i++){
           sum+=A[i];
       }
       int end=sum;
       
       while(start<=end){
           int mid=start+((end-start)/2);
           if(canBe(A,N,M,mid)){
               ans=mid;
               end=mid-1;
           }else{
               start=mid+1;
           }
       }
       return ans;
       
       
   }
};
// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends