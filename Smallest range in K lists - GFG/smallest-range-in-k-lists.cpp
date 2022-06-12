// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
          //code here
          int i,minelem=INT_MAX,maxelem=INT_MIN,ans=INT_MAX,mini,maxi;
          priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
          for(i=0;i<k;i++)
          {
              pq.push({arr[i][0],{i,0}});
              maxelem=max(maxelem,arr[i][0]);
          }
          while(1)
          {
              pair<int,pair<int,int>> p=pq.top();
              pq.pop();
              minelem=p.first;
              if((maxelem-minelem)<ans)
              {
                  ans=maxelem-minelem;
                  mini=minelem;
                  maxi=maxelem;
              }
              if(p.second.second+1<n)
              {
                  maxelem=max(maxelem,arr[p.second.first][p.second.second+1]);
                  pq.push({arr[p.second.first][p.second.second+1],{p.second.first,p.second.second+1}});
              }
              else
              break;
          }
          return {mini,maxi};
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends