// Last updated: 9/7/2026, 1:38:09 PM
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