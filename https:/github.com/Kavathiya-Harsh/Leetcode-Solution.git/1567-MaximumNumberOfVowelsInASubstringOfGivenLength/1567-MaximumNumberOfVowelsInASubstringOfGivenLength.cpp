// Last updated: 7/31/2026, 1:27:14 PM
class Solution {
public:
    bool isvowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int count = 0;

        for (int i = 0; i < k; i++) {
            if (isvowel(s[i])) count++;
        }

        int ans = count;

        for (int i = k; i < s.size(); i++) {
            if (isvowel(s[i])) count++;
            if (isvowel(s[i - k])) count--;

            ans = max(ans, count);
        }

        return ans;
    }
};