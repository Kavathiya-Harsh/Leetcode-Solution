// Last updated: 7/28/2026, 1:37:41 PM
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> g(n+1);

        for (auto &r : roads) {
            g[r[0]].push_back({r[1], r[2]});
            g[r[1]].push_back({r[0], r[2]});
        }

        vector<int> vis(n+1, 0);
        queue<int> q;
        q.push(1);
        vis[1] = 1;

        int ans = INT_MAX;

        while (!q.empty()) {
            int u = q.front(); q.pop();

            for (auto &p : g[u]) {
                int v = p.first, d = p.second;

                ans = min(ans, d); // track min edge

                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        return ans;
    }
};