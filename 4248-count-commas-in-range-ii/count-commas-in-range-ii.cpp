class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        for (long long x = 1000, c = 1; x <= n; x *= 1000, c++) {
            long long end = min(n, x * 1000 - 1);
            ans += (end - x + 1) * c;
        }

        return ans;
    }
};