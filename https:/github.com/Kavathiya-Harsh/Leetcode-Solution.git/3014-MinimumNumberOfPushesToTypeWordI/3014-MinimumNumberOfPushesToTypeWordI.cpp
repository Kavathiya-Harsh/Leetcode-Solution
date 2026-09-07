// Last updated: 9/7/2026, 1:39:52 PM
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