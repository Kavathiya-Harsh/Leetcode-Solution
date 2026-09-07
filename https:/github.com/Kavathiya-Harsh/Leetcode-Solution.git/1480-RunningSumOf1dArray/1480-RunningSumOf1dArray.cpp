// Last updated: 9/7/2026, 1:42:19 PM
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i =1 ; i< nums.size();i++){
          nums[i] +=nums[i-1];
        }
        return nums;
    }
};