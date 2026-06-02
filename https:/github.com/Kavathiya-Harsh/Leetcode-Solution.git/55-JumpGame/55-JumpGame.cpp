// Last updated: 6/2/2026, 9:46:35 AM
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;

        for (int i = 0 ;i< nums.size();i++){
          if(i> reach)return false;
          reach = max(reach,i+nums[i]);
        }
      return true;
    }
};