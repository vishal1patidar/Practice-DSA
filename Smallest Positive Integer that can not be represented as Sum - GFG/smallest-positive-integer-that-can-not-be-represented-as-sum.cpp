// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution
{   
public:
     long long smallestpositive(vector<long long> array, int n)
   { 
       sort(array.begin(),array.end());
       long long sum=0;
       if(array[0]>1)return 1; //if first ele is greater than 1 then 1 is smallest positive integer 
       for(int i=0;i<n-1;i++){
           sum+=array[i];
           int diff=array[i+1]-array[i];
           if(diff >1 && sum+1<array[i+1]){
               return sum+1;
           }
       }
       sum+=array[n-1]; //if all array ele does not match add last ele and retrun sum+1
       return sum+1;
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
        vector<long long> array(n);
        for (int i = 0; i < n; ++i)
        {
            cin>>array[i];
        }
        Solution ob;
        cout<<ob.smallestpositive(array,n)<<"\n";
    }
    return 0; 
} 
  // } Driver Code Ends