// Last updated: 9/7/2026, 1:38:59 PM
class Solution {
public:
    string processStr(string s) {
        string result = "";

        for (char ch : s) {
            if (islower(ch)) {
                result += ch;  // append
            }
            else if (ch == '*') {
                if (!result.empty()) {
                    result.pop_back();  // remove last
                }
            }
            else if (ch == '#') {
                result += result;  // duplicate
            }
            else if (ch == '%') {
                reverse(result.begin(), result.end());  // reverse
            }
        }

        return result;
    }
};