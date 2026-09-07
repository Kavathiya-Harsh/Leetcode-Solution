// Last updated: 9/7/2026, 1:42:41 PM
class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '6') {
                s[i] = '9';
                break;
            }
        }
        return stoi(s);
    }
};