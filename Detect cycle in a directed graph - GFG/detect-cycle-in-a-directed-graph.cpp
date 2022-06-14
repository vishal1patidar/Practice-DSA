// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
   public:
   // Function to detect cycle in a directed graph.
   vector<bool> visited;
   vector<pair<int,int>> dp;
   bool dfs(int node,vector<int> adj[])
   {
       if(dp[node].first)
       return dp[node].second;
       
       if(adj[node].size()==0)
           return false;
       
       bool cycle = true;
       if(!visited[node])
       {
           visited[node] = true;
           for(auto i: adj[node])
               {
                   cycle = dfs(i,adj);
                   if(cycle)
                       break;
               }
               dp[node].first = true;
               visited[node] = false;
               
       }
       // cout<<node<<endl;
       return dp[node].second = cycle;
   }
   bool isCyclic(int V, vector<int> adj[]) {
       // code here
       dp.assign(V,make_pair(false,false));
       for(int i=0;i<V;i++)
       {
           visited.assign(V,false);
                  if(dfs(i,adj))
                    return true;
           
       }
       
       
       return false;
   }
};



// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends