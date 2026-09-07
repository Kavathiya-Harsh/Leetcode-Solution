// Last updated: 9/7/2026, 1:39:54 PM
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];

        // Find longest sequential prefix
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1)
                sum += nums[i];
            else
                break;
        }

        // Find smallest missing number >= sum
        while (find(nums.begin(), nums.end(), sum) != nums.end())
            sum++;

        return sum;
    }
};