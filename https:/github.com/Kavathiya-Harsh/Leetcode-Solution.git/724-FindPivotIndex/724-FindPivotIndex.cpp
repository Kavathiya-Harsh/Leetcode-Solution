// Last updated: 6/2/2026, 9:46:03 AM
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int total = 0;

    // sum
      for(int i = 0; i< nums.size();i++){
        total +=nums[i];
      }  

      int leftSum = 0;
      for(int i = 0; i<nums.size(); i++){
        int rightSum = total-leftSum-nums[i];

        if(leftSum == rightSum){
          return i;
        }
        leftSum += nums[i];
      }
      return -1;
    }
};