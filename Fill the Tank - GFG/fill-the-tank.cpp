// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {

public:
    long long TOTAL_WATER_IN_CORP=1e18;
    bool overDemand=false;
    
    long long dfs(int node, list<int> *adj, int parent, int *cap){
        long long waterSupplyinEachBranch=0;
        int branches=0;
        for(auto nei: adj[node]){
            if(parent!=nei){
               branches++;
               waterSupplyinEachBranch=max(waterSupplyinEachBranch,dfs(nei,adj,node,cap));
            }
        }
        long long waterRequired=cap[node-1]+(waterSupplyinEachBranch*branches);
        if(waterRequired>TOTAL_WATER_IN_CORP){
            overDemand=true;
        }
        return waterRequired;
    }
    long long minimum_amount(vector<vector<int>> &v, int num, int start, int *cap){
        list<int> adj[num+1];
        for(int i=0;i<v.size()-1;i++){
           adj[v[i][0]].push_back(v[i][1]);
           adj[v[i][1]].push_back(v[i][0]);
        }
        long long res=dfs(start,adj,-1,cap);
        if(overDemand==true){
            return -1;
        }
        return res;
    }
};

// { Driver Code Starts.


int main()
 {
	int T;
	cin>> T;
	while (T--)
	{
	    int num, start;
	    cin>>num>>start;
	    int cap[num];
	    for(int i = 0; i<num; i++)
	        cin>>cap[i];
	    
	    vector<vector<int>> Edges(num);
	    for(int i=1;i < num;i++){
	        int u, v; cin >> u >> v;
	        Edges[i-1].push_back(u);
	        Edges[i-1].push_back(v);
	    }
	    
	    
    	Solution obj;
	    long long ans = obj.minimum_amount(Edges, num, start, cap);
	    cout << ans << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends