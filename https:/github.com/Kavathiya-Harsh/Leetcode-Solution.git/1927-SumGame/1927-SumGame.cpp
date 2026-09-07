// Last updated: 9/7/2026, 1:41:20 PM
class Solution {
public:
    bool sumGame(string s) {
        int n = s.size(), d = 0, q = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '?') q += (i < n/2 ? 1 : -1);
            else d += (i < n/2 ? 1 : -1) * (s[i] - '0');
        }

        return q % 2 || d != -9 * q / 2;
    }
};