// Last updated: 9/7/2026, 1:39:40 PM
class Solution {
public:
    long long gcd(long long a, long long b) {
        return b ? gcd(b, a % b) : a;
    }

    long long count(long long x, vector<int>& c) {
        long long ans = 0;
        int n = c.size();

        for (int mask = 1; mask < (1 << n); mask++) {
            long long l = 1;
            int bits = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;
                    l = l / gcd(l, c[i]) * c[i];
                    if (l > x) break;
                }
            }

            if (l <= x) {
                if (bits & 1) ans += x / l;
                else ans -= x / l;
            }
        }
        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long l = 1, r = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (l < r) {
            long long mid = (l + r) / 2;

            if (count(mid, coins) >= k)
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};