// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minValue(int a[], int b[], int n)
    {
        long long int res=0;
   priority_queue<int> mypq(a, a+n);    //9 8 7 7 6 5 4 3
   multiset<int> :: iterator it;
   multiset<int> myset(b, b+n);              //{1,2,3,4,6,7,8,9}
   it=myset.begin();
   
   while(n>0){
       res = res+( (*it) * (mypq.top()));
       it++;
       mypq.pop();
       n--;
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
         int n, i;
         cin>>n;
         int a[n], b[n];
         for(i=0;i<n;i++)
         cin>>a[i];
         for(i=0;i<n;i++)
         cin>>b[i];
         Solution ob;
         cout<< ob.minValue(a, b, n) <<endl;
     }
	
	return 0;
}  // } Driver Code Ends