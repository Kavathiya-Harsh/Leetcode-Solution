// Last updated: 6/13/2026, 11:51:04 AM
class Solution {
public:
    int digitFrequencyScore(int n) {
        int ans = 0;

        while (n > 0) {
            ans += n % 10;
            n /= 10;
        }

        return ans;
    }
};