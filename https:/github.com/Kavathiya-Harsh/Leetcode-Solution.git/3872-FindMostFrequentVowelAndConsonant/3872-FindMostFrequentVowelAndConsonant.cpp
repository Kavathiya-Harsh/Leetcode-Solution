// Last updated: 6/15/2026, 9:22:23 AM
class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);

        // Step 1: Count frequency
        for(char c : s) {
            freq[c - 'a']++;
        }

        int maxVowel = 0;
        int maxConsonant = 0;

        // Step 2: Check each character
        for(int i = 0; i < 26; i++) {
            char ch = 'a' + i;

            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                maxVowel = max(maxVowel, freq[i]);
            } else {
                maxConsonant = max(maxConsonant, freq[i]);
            }
        }

        // Step 3: Return sum
        return maxVowel + maxConsonant;
    }
};