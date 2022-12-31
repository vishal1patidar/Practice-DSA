class Solution {
public:
    // variables to use in our solution
    vector<vector<int>> grid;
    int m, n, c;
    // memo table - dp[state] = # of paths to end from that state
    // C++ doesn't like hashing pairs, so square s with visited set k is represented by (s << 20) + k
    // since the maximum size of the visited set is 20.
    unordered_map<int, int> dp;
    int solve(int x, int y, int visited) {
        int a = n * x + y; // find the number of this square
        int id = ((n * x + y) << 20) + visited; // generate memo table id
        // if we have already solved this state, return value
        if(dp.count(id) > 0) return dp[id];
        // base case - if we're at the end, check if we have visited enough grid squares before
        if(grid[x][y] == 2) return (__builtin_popcount(visited) == c ? 1 : 0);
        // output variable
        int res = 0;
        // new visited set
        int nvis = visited | (1 << a);
        // try going up
        if(x > 0 && grid[x - 1][y] != -1 && (visited & (1 << (a - n))) == 0) {
            res += solve(x - 1, y, nvis);
        }
        // try going down
        if(x + 1 < m && grid[x + 1][y] != -1 && (visited & (1 << (a + n))) == 0) {
            res += solve(x + 1, y, nvis);
        }
        // try going left
        if(y > 0 && grid[x][y - 1] != -1 && (visited & (1 << (a - 1))) == 0) {
            res += solve(x, y - 1, nvis);
        }
        // try going right
        if(y + 1 < n && grid[x][y + 1] != -1 && (visited & (1 << (a + 1))) == 0) {
            res += solve(x, y + 1, nvis);
        }
        // memoize result before we return so that we can reuse it
        dp[id] = res;
        return res;
    }

    int uniquePathsIII(vector<vector<int>>& g) {
        // initialize some variables for the search
        grid = g;
        m = grid.size();
        n = grid[0].size();
        // find starting square
        int x, y;
        // count number of non-obstacle, non-end squares
        c = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) {
                    x = i;
                    y = j;
                }
                if(grid[i][j] == 1 || grid[i][j] == 0) ++c;
            }
        }
        // call DP solution
        return solve(x, y, 0);
    }
};