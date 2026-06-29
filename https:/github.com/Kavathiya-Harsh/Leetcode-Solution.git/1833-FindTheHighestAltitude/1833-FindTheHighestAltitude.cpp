// Last updated: 6/29/2026, 8:46:27 AM
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