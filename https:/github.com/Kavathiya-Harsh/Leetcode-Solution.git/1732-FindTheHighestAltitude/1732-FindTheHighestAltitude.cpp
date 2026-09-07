// Last updated: 9/7/2026, 1:41:51 PM
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int current = 0, maxAlt = 0;

        for (int g : gain) {
            current += g;
            maxAlt = max(maxAlt, current);
        }

        return maxAlt;
    }
};