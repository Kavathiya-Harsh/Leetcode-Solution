// Last updated: 12/05/2026, 16:53:58
class Solution {
public:
    bool isPalindrome(string s) {
        string word = "";

        for (char ch : s) {
            // valid character check
            if ((ch >= 'a' && ch <= 'z') || 
                (ch >= 'A' && ch <= 'Z') || 
                (ch >= '0' && ch <= '9')) {

                // uppercase -> lowercase
                if (ch >= 'A' && ch <= 'Z') {
                    ch = ch + 32;
                }

                word += ch;
            }
        }

        // palindrome check
        int n = word.size();
        for (int i = 0; i < n / 2; i++) {
            if (word[i] != word[n - i - 1]) {
                return false;
            }
        }

        return true;
    }
};