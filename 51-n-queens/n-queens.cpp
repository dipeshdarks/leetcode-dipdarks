class Solution {
public:
    vector<vector<string>> result;

    void backtrack(int row, int n,
                   vector<string>& board,
                   vector<bool>& cols,
                   vector<bool>& diag1,
                   vector<bool>& diag2) {

        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            // Check if queen can be placed
            if (cols[col] || diag1[row - col + n - 1] || diag2[row + col])
                continue;

            // Place queen
            board[row][col] = 'Q';
            cols[col] = true;
            diag1[row - col + n - 1] = true;
            diag2[row + col] = true;

            backtrack(row + 1, n, board, cols, diag1, diag2);

            // Remove queen (backtrack)
            board[row][col] = '.';
            cols[col] = false;
            diag1[row - col + n - 1] = false;
            diag2[row + col] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        vector<bool> cols(n, false);

        // There are 2*n - 1 diagonals in each direction
        vector<bool> diag1(2 * n - 1, false); // row - col
        vector<bool> diag2(2 * n - 1, false); // row + col

        backtrack(0, n, board, cols, diag1, diag2);

        return result;
    }
};