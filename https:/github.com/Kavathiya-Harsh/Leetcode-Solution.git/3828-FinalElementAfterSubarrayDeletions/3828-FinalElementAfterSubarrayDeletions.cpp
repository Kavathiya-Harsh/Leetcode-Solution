// Last updated: 9/7/2026, 1:38:23 PM
class Solution {
public:
    int finalElement(vector<int>& nums) {
        return max(nums.front(), nums.back());
    }
};