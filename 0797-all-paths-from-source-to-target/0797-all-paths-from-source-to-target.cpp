class Solution {
public:
    void path(int src,int tar,vector<int> adj[],vector<int>& temp,vector<vector<int>>& ans)
    {
        temp.push_back(src);                        // each time store the current node
        if(src==tar)                                // if we reached to the tar then pysh this path to our answer
        {
            ans.push_back(temp);
            return;
        }
        
        // try out all possible paths for curr source node
        for(auto it : adj[src])
        {
            path(it,tar,adj,temp,ans);
            temp.pop_back();                          // after taking this path just remove the last element from out temp path
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        // storing the graph
        int n = graph.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[i].push_back(graph[i][j]);
            }
        }
        
        vector<vector<int>> ans;                   // for storing the list of answers
        vector<int> temp;                          // for storing the path from src to dest
        path(0,n-1,adj,temp,ans);
        return ans;
    }
};