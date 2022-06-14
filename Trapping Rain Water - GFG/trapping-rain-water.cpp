// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
         long long ans=0;
       int larr[n],rarr[n];
       int maxi=INT_MIN;
       for(int i=0;i<n;i++){
           maxi=max(maxi,arr[i]);
           larr[i]=maxi;
       }
       maxi=INT_MIN;
       for(int i=n-1;i>=0;i--){
           maxi=max(maxi,arr[i]);
           rarr[i]=maxi;
       }
       for(int i=0;i<n;i++){
       ans+=min(larr[i],rarr[i])-arr[i];
       }
       
       return ans;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends