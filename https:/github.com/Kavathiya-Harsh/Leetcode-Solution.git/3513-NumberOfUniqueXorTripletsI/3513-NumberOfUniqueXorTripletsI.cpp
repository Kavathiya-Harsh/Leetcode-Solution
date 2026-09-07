// Last updated: 9/7/2026, 1:39:22 PM
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return n;
        return 1 << (32 - __builtin_clz(n));
    }
};