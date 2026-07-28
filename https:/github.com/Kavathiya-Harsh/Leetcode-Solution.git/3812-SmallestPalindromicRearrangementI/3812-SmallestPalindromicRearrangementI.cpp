// Last updated: 7/28/2026, 1:37:31 PM
class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> cnt(26, 0);

        for (char c : s) cnt[c - 'a']++;

        string left = "", right = "";
        char mid = '\0';

        for (int i = 0; i < 26; i++) {
            left.append(cnt[i] / 2, 'a' + i);
            if (cnt[i] % 2) mid = 'a' + i;
        }

        right = left;
        reverse(right.begin(), right.end());

        return mid ? left + mid + right : left + right;
    }
};