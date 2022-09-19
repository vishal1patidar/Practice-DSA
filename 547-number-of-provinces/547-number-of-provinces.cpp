// The 2 Approaches:

// Depth First Search
// Breadth First Search
// Code to convert Adjacency Matrix to Adjacency List
// Depth First Search:
// Time Complexity: O(V)[For loop] + O(V+ 2E) [Recursion Calls+Total no of times the for loop inside it is called]
// Space Complexity: O(V) [Visted Array] + O(V) [Stack Space]
class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, int V){
        visited[node] = 1;
        
        for(int i=0;i<V;i++){
            if(adj[node-1][i] == 1 && i != node-1 && !visited[i+1]){
                dfs(i+1,adj,visited,V);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int V = adj.size();
        int cnt = 0;
        
        vector<int> visited(V+1,0);
        
        for(int i=1;i<=V;i++){
            if(!visited[i]){
                dfs(i,adj,visited, V);
                cnt++;
            }
        }
        
        return cnt;
    }
};
// Breadth First Search:
// Time Complexity: O(V) + O(V + 2E)
// Space Complexity: O(V) [Visited Array]
// class Solution {
// public:
//     int findCircleNum(vector<vector<int>>& adj) {
//         int V = adj.size();
//         int cnt = 0;
        
//         vector<int> visited(V+1,0);
        
//         for(int i=1;i<=V;i++){
//             if(!visited[i]){
//                 queue<int> q;
//                 q.push(i);
//                 visited[i] = 1;
                
//                 while(!q.empty()){
//                     int node = q.front();
//                     q.pop();

//                     for(int i=0;i<V;i++){
//                         if(adj[node-1][i] == 1 && i != node-1 && !visited[i+1]){
//                             visited[i+1] = 1;
//                             q.push(i+1);
//                         }
//                     }
//                 }
//                 cnt++;
//             }
//         }
        
//         return cnt;
//     }
// };
// Code to convert Adjacency Matrix to Adjcency List
// vector<int> adjLis(V);
// for(int i=0;i<V;i++){
// 	for(int j=0;j<V;j++){
// 		if(adjMat[i][j] == 1 && i!=j){
// 			adjLis[i].push_back(j);
// 			adjLis[j].push_back(i);
// 		}
// 	}
// }