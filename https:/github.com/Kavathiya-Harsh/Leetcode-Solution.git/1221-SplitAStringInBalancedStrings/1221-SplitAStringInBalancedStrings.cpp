// Last updated: 9/7/2026, 1:42:47 PM
class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int ans = 0;

        for(char c : s) {
            if(c == 'R') count++;
            else count--;

            if(count == 0) {
                ans++;   // one balanced substring found
            }
        }

        return ans;
    }
};