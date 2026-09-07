// Last updated: 9/7/2026, 1:38:39 PM
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mx = *max_element(nums.begin(), nums.end());
        long long mn = *min_element(nums.begin(), nums.end());

        return (mx - mn) * 1LL * k;
    }
};