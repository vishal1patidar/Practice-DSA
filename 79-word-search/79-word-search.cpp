class Solution {
private:
    vector<vector<int>> directions = {
        {0, 1},
        {0, -1},
        {-1, 0},
        {1, 0}
    };

    bool backtracking(vector<vector<char>>& board, string &word, int index, int row, int col)
    {
        char current = word[index];
        if (board[row][col] != current) return false;
        if (index + 1 == word.length()) return true;

        for (const auto &dir: directions)
        {
            int r = row + dir[0];
            int c = col + dir[1];
            if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size())
            {
                continue;
            }
            board[row][col] = '#';  // mark the path as visited
            if (backtracking(board, word, index + 1, r, c))
            {
                return true;
            }
            board[row][col] = current;
        }

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        char startPoint = word[0];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (backtracking(board, word, 0, i, j))
                {
                    return true;
                }
            }
        }

        return false;
    }
};