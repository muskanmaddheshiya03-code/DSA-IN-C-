#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> solutions;
        std::vector<std::string> board(n, std::string(n, '.'));
        
        std::vector<bool> cols(n, false);
        std::vector<bool> mainDiag(2 * n - 1, false); 
        std::vector<bool> antiDiag(2 * n - 1, false); 
        
        backtrack(0, n, board, solutions, cols, mainDiag, antiDiag);
        return solutions;
    }

private:
    void backtrack(int row, int n, std::vector<std::string>& board, 
                   std::vector<std::vector<std::string>>& solutions,
                   std::vector<bool>& cols, std::vector<bool>& mainDiag, 
                   std::vector<bool>& antiDiag) {
        if (row == n) {
            solutions.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            int mdIdx = row - col + (n - 1);
            int adIdx = row + col;

            if (cols[col] || mainDiag[mdIdx] || antiDiag[adIdx]) {
                continue;
            }
            board[row][col] = 'Q';
            cols[col] = mainDiag[mdIdx] = antiDiag[adIdx] = true;
            backtrack(row + 1, n, board, solutions, cols, mainDiag, antiDiag);
            board[row][col] = '.';
            cols[col] = mainDiag[mdIdx] = antiDiag[adIdx] = false;
        }
    }
};