// Last updated: 7/28/2026, 1:37:28 PM
class Solution {
public:
    vector<int> parent;

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        parent[find(a)] = find(b);
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);

        for (int i = 1; i < n; i++)
            if (nums[i] - nums[i - 1] <= maxDiff)
                unite(i, i - 1);

        vector<bool> ans;
        for (auto &q : queries)
            ans.push_back(find(q[0]) == find(q[1]));

        return ans;
    }
};