class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;

                if (len == 1)
                    dp[i][j] = true;
                else if (len == 2)
                    dp[i][j] = (s[i] == s[j]);
                else
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
            }
        }

        vector<int> ans(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            ans[i] = ans[i - 1];

            for (int j = 0; j < i; j++) {
                if (i - j >= k && dp[j][i - 1]) {
                    ans[i] = max(ans[i], ans[j] + 1);
                }
            }
        }

        return ans[n];
    }
};