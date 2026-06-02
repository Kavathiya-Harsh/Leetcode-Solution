// Last updated: 6/2/2026, 9:45:56 AM
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i =1 ; i< nums.size();i++){
          nums[i] +=nums[i-1];
        }
        return nums;
    }
};