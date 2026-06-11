// Last updated: 6/11/2026, 8:11:49 AM
class Solution {
public:
    struct State {
        long long count, waviness;
    };

    string num;
    State dp[16][11][11];
    bool vis[16][11][11];

    State dfs(int pos, int prev2, int prev1, bool tight) {
        if (pos == num.size())
            return {1, 0};

        if (!tight && vis[pos][prev2][prev1])
            return dp[pos][prev2][prev1];

        int limit = tight ? num[pos] - '0' : 9;

        State res = {0, 0};

        for (int d = 0; d <= limit; d++) {
            bool newTight = tight && (d == limit);

            long long add = 0;

            if (prev2 != 10) {
                if ((prev1 > prev2 && prev1 > d) ||
                    (prev1 < prev2 && prev1 < d))
                    add = 1;
            }

            State nxt = dfs(pos + 1, prev1, d, newTight);

            res.count += nxt.count;
            res.waviness += nxt.waviness + add * nxt.count;
        }

        if (!tight) {
            vis[pos][prev2][prev1] = true;
            dp[pos][prev2][prev1] = res;
        }

        return res;
    }

    long long solve(long long x) {
        if (x < 100) return 0;

        num = to_string(x);

        memset(vis, 0, sizeof(vis));

        State ans = {0, 0};

        for (int len = 1; len < num.size(); len++) {
            string old = num;
            num = string(len, '9');

            memset(vis, 0, sizeof(vis));

            for (int first = 1; first <= 9; first++) {
                State cur = dfs(1, 10, first, false);
                ans.waviness += cur.waviness;
            }

            num = old;
        }

        memset(vis, 0, sizeof(vis));

        int firstLimit = num[0] - '0';

        for (int first = 1; first <= firstLimit; first++) {
            State cur = dfs(
                1,
                10,
                first,
                first == firstLimit
            );

            ans.waviness += cur.waviness;
        }

        return ans.waviness;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};