// Last updated: 9/7/2026, 1:41:11 PM
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx = word.find(ch);

        if (idx == string::npos)
            return word;

        reverse(word.begin(), word.begin() + idx + 1);

        return word;
    }
};