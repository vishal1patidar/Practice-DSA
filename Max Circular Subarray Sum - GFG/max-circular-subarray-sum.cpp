// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
   
   
int kadane(int arr[],int n){
   int currentsum=0;
   int maxsum = INT_MIN;

   for(int i=0;i<n;i++){
       currentsum+=arr[i];
        maxsum=max(maxsum,currentsum);
       if(currentsum<0){
           currentsum=0;
       }
      
   }
   return maxsum;
}
   
   
   
   
int ansfinder(int arr[],int n){
       
   int nonwrapsum=kadane(arr,n);

   int wrapsum;

   int totalsum=0;
   for(int i=0;i<n;i++){
       totalsum+=arr[i];
       arr[i]=-arr[i];
   }

   // wrapsum =totalsum - ( - kadane(arr,n) )
   wrapsum =totalsum + kadane(arr,n);
   
   
   int ans = max(wrapsum,nonwrapsum);
   
   if(wrapsum < 0 && nonwrapsum == 0 || wrapsum == 0 && nonwrapsum < 0){
       return min( wrapsum ,nonwrapsum);
   }
   else{
       return max(wrapsum,nonwrapsum);
   }

}
  
public:
   
int circularSubarraySum(int arr[], int num){
       return ansfinder(arr,num);
}
};
// { Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends