// Last updated: 6/29/2026, 8:45:52 AM
class Solution {
public:
    static const int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<long long> up(m + 1, 0);
        vector<long long> down(m + 1, 0);

        // Length = 2
        for (int v = 1; v <= m; v++) {
            up[v] = v - 1;      // smaller values
            down[v] = m - v;    // larger values
        }

        // Build lengths 3 ... n
        for (int len = 3; len <= n; len++) {
            vector<long long> newUp(m + 1, 0);
            vector<long long> newDown(m + 1, 0);

            // Prefix sums of down
            long long pref = 0;
            for (int v = 1; v <= m; v++) {
                newUp[v] = pref;
                pref = (pref + down[v]) % MOD;
            }

            // Suffix sums of up
            long long suff = 0;
            for (int v = m; v >= 1; v--) {
                newDown[v] = suff;
                suff = (suff + up[v]) % MOD;
            }

            up = move(newUp);
            down = move(newDown);
        }

        long long ans = 0;

        for (int v = 1; v <= m; v++) {
            ans = (ans + up[v] + down[v]) % MOD;
        }

        return (int)ans;
    }
};