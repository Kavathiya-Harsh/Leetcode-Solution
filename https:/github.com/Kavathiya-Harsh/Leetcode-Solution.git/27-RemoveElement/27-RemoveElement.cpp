// Last updated: 6/2/2026, 9:46:37 AM
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;

        for(int i = 0; i< nums.size(); i++){
          if (nums[i] != val){
            nums[k] = nums[i];
            k++;
          }
        }
        return k;
    }
};