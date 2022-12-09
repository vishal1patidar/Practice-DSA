//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
/*You are required to complete this method */
class Solution

{

    public:

    int josephus(int n, int k)

    {

       //Your code here

       list<int> l;

       for(int i = 0 ;i<n;i++)

       {

           l.push_back(i);

       }

       auto it = l.begin();

       while(l.size()>1)

       {

           for(int count = 1; count<k; count++)

           {

               it++;

               if(it == l.end())

               it = l.begin();

           }

           it = l.erase(it);

           if(it == l.end())

                it = l.begin();

       }

       return *l.begin()+1;

    }
};




//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends