// Last updated: 9/7/2026, 1:42:08 PM
class Solution {
public:
    int stoneGameV(vector<int>& a) {
        int n = a.size();
        vector<int> p(n + 1);
        for (int i = 0; i < n; i++) p[i + 1] = p[i] + a[i];

        vector<vector<int>> dp(n, vector<int>(n));

        for (int len = 2; len <= n; len++)
            for (int l = 0; l + len <= n; l++) {
                int r = l + len - 1;

                for (int k = l; k < r; k++) {
                    int x = p[k + 1] - p[l];
                    int y = p[r + 1] - p[k + 1];

                    if (x <= y)
                        dp[l][r] = max(dp[l][r], x + dp[l][k]);
                    if (y <= x)
                        dp[l][r] = max(dp[l][r], y + dp[k + 1][r]);
                }
            }

        return dp[0][n - 1];
    }
};