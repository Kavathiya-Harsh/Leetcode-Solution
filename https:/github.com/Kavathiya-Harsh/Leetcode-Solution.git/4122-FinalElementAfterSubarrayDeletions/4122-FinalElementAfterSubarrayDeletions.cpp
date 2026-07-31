// Last updated: 7/31/2026, 1:25:19 PM
class Solution {
public:
    int finalElement(vector<int>& nums) {
        return max(nums.front(), nums.back());
    }
};