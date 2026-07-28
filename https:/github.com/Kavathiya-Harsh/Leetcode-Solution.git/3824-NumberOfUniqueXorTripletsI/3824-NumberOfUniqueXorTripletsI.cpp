// Last updated: 7/28/2026, 1:37:29 PM
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return n;
        return 1 << (32 - __builtin_clz(n));
    }
};