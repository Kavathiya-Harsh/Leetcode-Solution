// Last updated: 9/7/2026, 1:42:11 PM
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> freq;
        int ans = 0;

        for (int num : nums) {
            ans += freq[num];
            freq[num]++;
        }
        return ans;
    }
};