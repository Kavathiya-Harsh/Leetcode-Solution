// Last updated: 9/7/2026, 1:43:36 PM
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }

        string doubled = s + s;
        return doubled.find(goal) != string::npos;
    }
};