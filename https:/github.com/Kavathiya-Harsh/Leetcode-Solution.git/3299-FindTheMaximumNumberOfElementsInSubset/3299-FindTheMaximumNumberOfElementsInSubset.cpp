// Last updated: 6/29/2026, 8:46:01 AM
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;

        for (int x : nums)
            cnt[x]++;

        int ans = 1;

        // Handle 1 separately
        if (cnt.count(1)) {
            ans = max(ans, cnt[1] % 2 ? cnt[1] : cnt[1] - 1);
        }

        for (auto &[x, f] : cnt) {
            if (x == 1) continue;

            long long cur = x;
            int len = 0;

            while (true) {
                if (!cnt.count(cur)) break;

                if (cnt[cur] == 1) {
                    len++;
                    break;
                }

                // Need two copies for left and right
                len += 2;

                // Prevent overflow
                if (cur > 1000000000LL / cur) {
                    len--;
                    break;
                }

                cur = cur * cur;
            }

            // Length must always be odd
            if (len % 2 == 0) len--;

            ans = max(ans, len);
        }

        return ans;
    }
};