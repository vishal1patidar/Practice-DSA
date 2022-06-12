// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
       
double helper(double m[],int n,double s,double e){
       double ans = -1;
       while(s <= e){
           double mid = (s+e)/2;
           
           double tf = 0.00;
           for(int i = 0; i < n; i++){
               tf += 1.0 / (mid - m[i]);
           }
           
           if(abs(tf) < 0.0000000001){
               ans = mid;
               break;
           }
           else if(tf >= 0){
               ans = mid;
               s = mid + 0.000000000001;
           }
           else{
               e = mid - 0.000000000001;
           }
       }
       return (ans);
   }
   
   void nullPoints(int n, double magnets[], double getAnswer[]){
       for(int i = 0; i < n-1; i++){
           getAnswer[i] = helper(magnets,n,magnets[i],magnets[i+1]);
       }
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
        double magnets[n], getAnswer[n];
        for(int i=0;i<n;i++)
        cin>>magnets[i];
        Solution ob;
        ob.nullPoints(n, magnets, getAnswer);
        
        for(int i=0; i<n-1; i++)
            printf("%0.2lf ",getAnswer[i]);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends