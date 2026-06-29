// Last updated: 6/29/2026, 8:46:43 AM
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        
        int n = s.size();
        int k = p.size();
        
        if (k > n) return ans;

        vector<int> freqP(26, 0), freqS(26, 0);

        // Build frequency for p
        for (char c : p) {
            freqP[c - 'a']++;
        }

        // First window
        for (int i = 0; i < k; i++) {
            freqS[s[i] - 'a']++;
        }

        if (freqP == freqS) ans.push_back(0);

        // Sliding window
        for (int i = k; i < n; i++) {
            freqS[s[i] - 'a']++;        // add new char
            freqS[s[i - k] - 'a']--;    // remove old char

            if (freqP == freqS) {
                ans.push_back(i - k + 1);
            }
        }

        return ans;
    }
};