// Last updated: 7/28/2026, 1:37:25 PM
class Solution {
public:
    using ll = long long;

    bool can(int x, vector<vector<pair<int,int>>> &g, vector<bool>& online, ll k) {
        int n = g.size();
        vector<ll> dist(n, LLONG_MAX);

        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;

            for (auto &p : g[u]) {
                int v = p.first, w = p.second;

                if (w < x || !online[v]) continue;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n-1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,int>>> g(n);
        int mx = 0;

        for (auto &e : edges) {
            g[e[0]].push_back({e[1], e[2]});
            mx = max(mx, e[2]);
        }

        int l = 0, r = mx, ans = -1;

        while (l <= r) {
            int m = (l + r) / 2;

            if (can(m, g, online, k)) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return ans;
    }
};