// Last updated: 9/7/2026, 1:38:06 PM
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";

        for (string word : words) {
            int sum = 0;

            for (char ch : word) {
                sum += weights[ch - 'a'];  // weight of character
            }

            int mod = sum % 26;
            char mapped = 'z' - mod;      // reverse mapping

            result += mapped;
        }

        return result;
    }
};