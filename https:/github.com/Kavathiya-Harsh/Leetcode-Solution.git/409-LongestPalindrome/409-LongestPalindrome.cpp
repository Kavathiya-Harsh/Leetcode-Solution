// Last updated: 6/11/2026, 8:12:19 AM
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;

        for (char ch : s) {
            freq[ch]++;
        }

        int length = 0;
        bool hasOdd = false;

        for (auto &it : freq) {
            if (it.second % 2 == 0) {
                length += it.second;
            } else {
                length += it.second - 1;
                hasOdd = true;
            }
        }

        return hasOdd ? length + 1 : length;
    }
};