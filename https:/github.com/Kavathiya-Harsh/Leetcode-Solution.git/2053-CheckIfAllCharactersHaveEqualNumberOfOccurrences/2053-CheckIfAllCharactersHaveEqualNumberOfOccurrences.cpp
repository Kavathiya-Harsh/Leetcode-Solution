// Last updated: 6/29/2026, 8:46:17 AM
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int freq[26] = {0};
        
        // Count frequency
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        int count = 0;
        
        // Check all frequencies are same
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                if (count == 0) count = freq[i];
                else if (freq[i] != count) return false;
            }
        }
        
        return true;
    }
};