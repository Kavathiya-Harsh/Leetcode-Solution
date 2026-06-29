// Last updated: 6/29/2026, 8:45:55 AM
class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;

        // Step 1: compute length
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                len++;
            } 
            else if (c == '*') {
                if (len > 0) len--;
            } 
            else if (c == '#') {
                len *= 2;
            } 
            // '%' → no change
        }

        // Out of bounds
        if (k >= len) return '.';

        // Step 2: reverse traversal
        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];

            if (c >= 'a' && c <= 'z') {
                if (k == len - 1) return c;
                len--;
            }
            else if (c == '*') {
                len++;  // reverse of delete
            }
            else if (c == '#') {
                len /= 2;
                if (k >= len) k -= len;
            }
            else if (c == '%') {
                k = len - k - 1;
            }
        }

        return '.';
    }
};