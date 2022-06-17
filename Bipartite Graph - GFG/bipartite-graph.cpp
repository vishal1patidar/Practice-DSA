// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> Col(V , -1);
	    for(int i=0; i<  V; i++){
	        if(Col[i] == -1){
	            if(!d_f_s(i , adj , Col , 1)) return  0;
	        }
	    }
	    return 1;
	}
	bool d_f_s(int node , vector<int> adj[], vector<int> &ver , int col){
	    if(ver[node] != -1 ){
	        if(ver[node] == col) return 1;
	        else return 0;
	    }
	    ver[node] = col;
	    for(int j : adj[node]){
	        if(! d_f_s(j , adj , ver ,  col ^ 1 )) return 0;
	    }
	    return 1;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends