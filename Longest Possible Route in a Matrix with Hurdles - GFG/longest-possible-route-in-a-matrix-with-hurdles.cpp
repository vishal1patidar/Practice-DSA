// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:

pair<int,int> direc[4]={{1,0},{0,1},{-1,0},{0,-1}}; //top right botttom left

    int ans=-1; int N; int M;

    void helper(vector<vector<int>> &matrix, int x, int y, int steps,pair<int,int> final){

        // if(x<0 || x>M || y<0 || y>=M)

        if(matrix[x][y]==-1) return;

        if(x==final.first && y==final.second){

            ans=max(ans,steps);

            return;

        } 

        for(int i=0;i<4;i++){

            int xx=x+direc[i].first;

            int yy=y+direc[i].second;

            if(xx>=0 && xx<N && yy>=0 && yy<M && matrix[xx][yy]!=0 && matrix[xx][yy]!=-1){

                int temp=matrix[x][y];

                matrix[x][y]=-1;

                helper(matrix,xx,yy,steps+1,final);

                matrix[x][y]=temp;

            }

        }

        return;

    }

    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)

    {

        // code here

        if(matrix[xs][ys]==0) return -1;

        N=matrix.size();

        M=matrix[0].size();

        pair<int,int> final={xd,yd};

        helper(matrix,xs,ys,0,final);

        return ans;
    
}
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends