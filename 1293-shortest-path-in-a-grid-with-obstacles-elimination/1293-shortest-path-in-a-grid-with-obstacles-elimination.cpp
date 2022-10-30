class Solution {
public:
    const int dx[4] = { -1, 0, 0, 1 }, dy[4] = { 0, -1, 1, 0 };
    // if you are working on 8 directions, then you can use
    // const int dx[8]= { -1, 0, 0, 1, -1, -1, 1, 1 },
    //           dy[8]= { 0, 1, -1, 0, -1, 1, -1, 1 };
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), steps = 0;
        vector<vector<int>> remains(m, vector<int>(n, INT_MIN));
        // we have a queue storing {x, y, k} 
        // where x and y are coordinate 
        // and r is remain number of obstacles you can remove
        queue<array<int, 3>> q;
        // we start at (0, 0) with k
        q.push({0, 0, k});
        // at the beginning, you can eliminate at most k obstacles
        remains[0][0] = k;
        // BFS
        while (!q.empty()) {
            for (int it = q.size(); it > 0; it--) {
                auto cur = q.front(); q.pop();
                // if we reach the lower right corner (m - 1, n - 1)
                // then return the minimum number of steps
                if (cur[0] == m - 1 && cur[1] == n - 1) return steps;
                // otherwise we can try 4 directions (up, down, left and right)
                for (int i = 0; i < 4; i++) {
                    // given we have at (x, y), we can move to (next_x, next_y)
                    int next_x = cur[0] + dx[i], next_y = cur[1] + dy[i];
                    // however, first we need to make sure (next_x, next_y) is within the grid
                    if(next_x < 0 || next_x >= m || next_y < 0 || next_y >= n) continue;
                    // then, we check if we can eliminate an obstacle and move there
                    int remain = cur[2] - grid[next_x][next_y];
                    // we can only do that when `remain` is greater or equal to 0
                    // and the target remaining k must be less than the current remaining k
                    if(remain >= 0 && remains[next_x][next_y] < remain) {
                        // push to the queue for further process
                        q.push({next_x, next_y, remain});
                        // update the remaining k
                        remains[next_x][next_y] = remain;
                    }
                }
            }
            // increase step count
            steps += 1;
        }
        // if we reach here, 
        // then it means it is not possible to find such walk 
        return -1;
    }
};
