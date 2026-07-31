// Last updated: 7/31/2026, 1:26:03 PM
class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;

        for (int i = 0; i < word.size(); i++) {
            ans += (i / 8) + 1;
        }

        return ans;
    }
};