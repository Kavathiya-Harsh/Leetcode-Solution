// Last updated: 6/11/2026, 8:11:45 AM
class Solution {
public:
    using ll = long long;

    struct Node {
        ll val;
        int l, r;

        bool operator<(const Node& other) const {
            return val < other.val;
        }
    };

    vector<vector<int>> mx, mn;
    vector<int> lg;

    ll getValue(int l, int r) {
        int k = lg[r - l + 1];

        int maxi = max(mx[k][l], mx[k][r - (1 << k) + 1]);
        int mini = min(mn[k][l], mn[k][r - (1 << k) + 1]);

        return (ll)maxi - mini;
    }

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        lg.resize(n + 1);
        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }

        int LOG = lg[n] + 1;

        mx.assign(LOG, vector<int>(n));
        mn.assign(LOG, vector<int>(n));

        for (int i = 0; i < n; i++) {
            mx[0][i] = nums[i];
            mn[0][i] = nums[i];
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                mx[j][i] = max(
                    mx[j - 1][i],
                    mx[j - 1][i + (1 << (j - 1))]
                );

                mn[j][i] = min(
                    mn[j - 1][i],
                    mn[j - 1][i + (1 << (j - 1))]
                );
            }
        }

        priority_queue<Node> pq;

        for (int l = 0; l < n; l++) {
            pq.push({getValue(l, n - 1), l, n - 1});
        }

        ll ans = 0;

        while (k--) {
            auto cur = pq.top();
            pq.pop();

            ans += cur.val;

            if (cur.r > cur.l) {
                int nr = cur.r - 1;
                pq.push({
                    getValue(cur.l, nr),
                    cur.l,
                    nr
                });
            }
        }

        return ans;
    }
};