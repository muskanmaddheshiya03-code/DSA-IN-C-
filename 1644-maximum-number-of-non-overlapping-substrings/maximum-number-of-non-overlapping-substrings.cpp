class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> l(26, INT_MAX), r(26, INT_MIN);
        
        for (int i = 0; i < n; ++i) {
            int ch = s[i] - 'a';
            l[ch] = min(l[ch], i);
            r[ch] = max(r[ch], i);
        }

        auto getRightBoundary = [&](int i) -> int {
            int right = r[s[i] - 'a'];
            for (int j = i; j <= right; ++j) {
                if (l[s[j] - 'a'] < i) return -1; 
                right = max(right, r[s[j] - 'a']);
            }
            return right;
        };

        vector<string> res;
        int last_end = -1;

        for (int i = 0; i < n; ++i) {
            if (i == l[s[i] - 'a']) {
                int right = getRightBoundary(i);
                if (right != -1) {
                    if (i > last_end) {
                        res.push_back("");
                    }
                    last_end = right;
                    res.back() = s.substr(i, right - i + 1);
                }
            }
        }

        return res;
    }
};