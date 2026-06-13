// Last updated: 6/13/2026, 11:51:12 AM
class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        const int MOD = 1e9 + 7;

        int n = edges.size() + 1;

        // Step 1: Build graph
        vector<vector<int>> graph(n + 1);
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        // Step 2: BFS to find max depth
        queue<pair<int,int>> q; // {node, depth}
        vector<bool> visited(n + 1, false);

        q.push({1, 0});
        visited[1] = true;

        int maxDepth = 0;

        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();

            maxDepth = max(maxDepth, depth);

            for (int nei : graph[node]) {
                if (!visited[nei]) {
                    visited[nei] = true;
                    q.push({nei, depth + 1});
                }
            }
        }

        // Step 3: Compute 2^(k-1)
        int k = maxDepth;

        long long result = 1;
        for (int i = 0; i < k - 1; i++) {
            result = (result * 2) % MOD;
        }

        return result;
    }
};