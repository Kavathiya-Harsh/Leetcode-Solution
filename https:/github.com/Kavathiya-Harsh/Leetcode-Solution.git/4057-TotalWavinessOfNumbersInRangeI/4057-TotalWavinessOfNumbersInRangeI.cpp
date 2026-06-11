// Last updated: 6/11/2026, 8:11:46 AM
class Solution {
public:
    int waviness(string &s) {
        int cnt = 0;

        for (int i = 1; i < s.size() - 1; i++) {
            if ((s[i] > s[i - 1] && s[i] > s[i + 1]) ||
                (s[i] < s[i - 1] && s[i] < s[i + 1])) {
                cnt++;
            }
        }

        return cnt;
    }

    int totalWaviness(int num1, int num2) {
        int ans = 0;

        for (int num = num1; num <= num2; num++) {
            string s = to_string(num);
            ans += waviness(s);
        }

        return ans;
    }
};