// Last updated: 9/7/2026, 1:40:05 PM
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int left = 0, ones = 0;

        for (int right = 0; right < s.size(); right++) {
            if (s[right] == '1')
                ones++;

            // Remove extra 1s
            while (ones > k) {
                if (s[left] == '1')
                    ones--;
                left++;
            }

            // Exactly k ones
            if (ones == k) {
                // Remove leading zeros
                int temp = left;
                while (temp <= right && s[temp] == '0')
                    temp++;

                string cur = s.substr(temp, right - temp + 1);

                if (ans == "" || cur.length() < ans.length() ||
                    (cur.length() == ans.length() && cur < ans)) {
                    ans = cur;
                }
            }
        }

        return ans;
    }
};