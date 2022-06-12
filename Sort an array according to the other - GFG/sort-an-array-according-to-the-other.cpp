// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std;


 // } Driver Code Ends
//User function template in C++


class Solution{
    public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]
    
    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
   {
       //Your code here
       map<int,int> mp;
       vector<int> ans;
       for(int i=0;i<N;i++)
       {
           mp[A1[i]]++;
           
       }
       
       for(int i=0;i<M;i++)
       {
           int x=A2[i];
           int freq=mp[x];
           for(int j=0;j<freq;j++)
           {
               ans.push_back(x);
               mp[x]=0;  // here do it freq to zero
           }
           
       }
      
       
       for(const auto&it:mp)
       
       {
            if(it.second>1)
           {
               int f=it.second;  // here f is for handle when A2 ans element not find A1 and handle more than
                                  //      one freq and then one time freq in sorted order 
               for(int i=0;i<f;i++)
           ans.push_back(it.first);
           }
           if(it.second==1)
           ans.push_back(it.first);
       }
       
       
       return ans;
   } 

 
};

// { Driver Code Starts.

int main(int argc, char *argv[]) 
{ 
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    
	    vector<int> a1(n);
	    vector<int> a2(m);
	    
	    for(int i = 0;i<n;i++){
	        cin >> a1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> a2[i];
	    }
	    
	    Solution ob;
	    a1 = ob.sortA1ByA2(a1, n, a2, m); 
	
	   
	    for (int i = 0; i < n; i++) 
		    cout<<a1[i]<<" ";
		
	    cout << endl;
	    
	    
	}
	return 0; 
} 
  // } Driver Code Ends