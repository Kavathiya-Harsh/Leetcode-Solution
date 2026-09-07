// Last updated: 9/7/2026, 1:39:29 PM
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int cnt[51] = {};

        for (int i = 0; i + k <= nums.size(); i++) {
            set<int> s(nums.begin() + i, nums.begin() + i + k);
            for (int x : s) cnt[x]++;
        }

        for (int i = 50; i >= 0; i--)
            if (cnt[i] == 1) return i;

        return -1;
    }
};