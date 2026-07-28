// Last updated: 7/28/2026, 1:37:14 PM
class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> pos, d;

        // store non-zero digits
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                d.push_back(s[i] - '0');
            }
        }

        int k = d.size();

        vector<long long> prefNum(k + 1, 0), prefSum(k + 1, 0), pow10(k + 1, 1);

        for (int i = 1; i <= k; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        for (int i = 0; i < k; i++) {
            prefNum[i + 1] = (prefNum[i] * 10 + d[i]) % MOD;
            prefSum[i + 1] = prefSum[i] + d[i];
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L + 1;

            long long x = (prefNum[R + 1] - (prefNum[L] * pow10[len]) % MOD + MOD) % MOD;
            long long sum = prefSum[R + 1] - prefSum[L];

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};