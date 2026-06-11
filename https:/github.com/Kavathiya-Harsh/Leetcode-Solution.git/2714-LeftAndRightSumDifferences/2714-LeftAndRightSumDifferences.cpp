// Last updated: 6/11/2026, 8:11:57 AM
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        vector<int> ans;

        for (int num : nums) {
            totalSum -= num; // rightSum
            ans.push_back(abs(leftSum - totalSum));
            leftSum += num;
        }

        return ans;
    }
};