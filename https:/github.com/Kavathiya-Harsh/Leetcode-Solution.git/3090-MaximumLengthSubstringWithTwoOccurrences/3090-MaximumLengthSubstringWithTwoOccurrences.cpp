// Last updated: 8/14/2026, 11:31:06 AM
1class Solution {
2public:
3    int maximumLengthSubstring(string s) {
4        vector<int> freq(26, 0);
5        int left = 0, ans = 0;
6
7        for (int right = 0; right < s.size(); right++) {
8            freq[s[right] - 'a']++;
9
10            while (freq[s[right] - 'a'] > 2) {
11                freq[s[left] - 'a']--;
12                left++;
13            }
14
15            ans = max(ans, right - left + 1);
16        }
17
18        return ans;
19    }
20};