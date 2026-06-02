// Last updated: 6/2/2026, 9:46:26 AM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for(int num : nums){
          ans ^= num;

        }
        return ans;
    }
};