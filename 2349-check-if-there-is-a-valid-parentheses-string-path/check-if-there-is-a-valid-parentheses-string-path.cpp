class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if ((m + n - 1) % 2 != 0)
            return false;

        vector<vector<set<int>>> dp(m, vector<set<int>>(n));

        if (grid[0][0] == '(')
            dp[0][0].insert(1);
        else
            return false;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                int change = (grid[i][j] == '(') ? 1 : -1;

                if (i > 0) {
                    for (int balance : dp[i - 1][j]) {
                        int nb = balance + change;
                        if (nb >= 0)
                            dp[i][j].insert(nb);
                    }
                }

                if (j > 0) {
                    for (int balance : dp[i][j - 1]) {
                        int nb = balance + change;
                        if (nb >= 0)
                            dp[i][j].insert(nb);
                    }
                }
            }
        }

        return dp[m - 1][n - 1].count(0);
    }
};