// Last updated: 7/31/2026, 1:27:35 PM
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size(), MOD = 1e9+7;

        vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(n, {-1, 0}));
        dp[n-1][n-1] = {0, 1}; // start from S

        for (int i = n-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {

                if (board[i][j] == 'X' || (i == n-1 && j == n-1)) continue;

                int best = -1, ways = 0;

                vector<pair<int,int>> v = {
                    (i+1<n)?dp[i+1][j]:make_pair(-1,0),
                    (j+1<n)?dp[i][j+1]:make_pair(-1,0),
                    (i+1<n&&j+1<n)?dp[i+1][j+1]:make_pair(-1,0)
                };

                for (auto &p : v) {
                    if (p.first == -1) continue;
                    if (p.first > best) best = p.first, ways = p.second;
                    else if (p.first == best) ways = (ways + p.second) % MOD;
                }

                if (best == -1) continue;

                if (board[i][j] != 'E')
                    best += board[i][j] - '0';

                dp[i][j] = {best, ways};
            }
        }

        if (dp[0][0].first == -1) return {0,0};
        return {dp[0][0].first % MOD, dp[0][0].second % MOD};
    }
};