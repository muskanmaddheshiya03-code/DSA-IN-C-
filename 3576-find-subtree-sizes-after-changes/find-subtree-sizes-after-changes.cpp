
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;
        vector<vector<int>> st(26);

        // DFS on original tree
        vector<pair<int, bool>> dfs;
        dfs.push_back({0, false});

        while (!dfs.empty()) {
            auto [u, visited] = dfs.back();
            dfs.pop_back();

            if (visited) {
                st[s[u] - 'a'].pop_back();
                continue;
            }

            int c = s[u] - 'a';

            if (!st[c].empty()) {
                newParent[u] = st[c].back();
            }

            st[c].push_back(u);
            dfs.push_back({u, true});

            for (int v : adj[u]) {
                dfs.push_back({v, false});
            }
        }

        // Build modified tree
        vector<vector<int>> tree(n);

        for (int i = 1; i < n; i++) {
            tree[newParent[i]].push_back(i);
        }

        // Calculate subtree sizes
        vector<int> ans(n, 1);
        vector<int> order = {0};

        for (int i = 0; i < order.size(); i++) {
            int u = order[i];
            for (int v : tree[u]) {
                order.push_back(v);
            }
        }

        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            ans[newParent[u]] += ans[u];
        }

        return ans;
    }
};
