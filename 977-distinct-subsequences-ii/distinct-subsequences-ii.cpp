class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        vector<long long> dp(s.length() + 1, 0);
        vector<int> last(26, -1);

        dp[0] = 1;   // empty subsequence

        for (int i = 1; i <= s.length(); i++) {

            int c = s[i - 1] - 'a';

            // Normally every old subsequence can either
            // take or not take current character
            dp[i] = (2 * dp[i - 1]) % MOD;

            // Remove duplicates caused by previous same character
            if (last[c] != -1) {
                dp[i] = (dp[i] - dp[last[c] - 1] + MOD) % MOD;
            }

            last[c] = i;
        }

        // Remove empty subsequence
        return (dp[s.length()] - 1 + MOD) % MOD;
    }
};