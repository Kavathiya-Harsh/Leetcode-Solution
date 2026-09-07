// Last updated: 9/7/2026, 1:38:24 PM
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());

        int x = k;

        while (s.count(x)) {
            x += k;
        }

        return x;
    }
};