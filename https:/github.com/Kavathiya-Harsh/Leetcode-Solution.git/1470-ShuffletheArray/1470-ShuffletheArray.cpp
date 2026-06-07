// Last updated: 6/7/2026, 3:23:19 PM
1class Solution {
2public:
3    vector<int> shuffle(vector<int>& nums, int n) {
4        vector<int>ans;
5
6        for (int i = 0;i<n; i++){
7          ans.push_back(nums[i]);
8          ans.push_back(nums[i+n]);
9        }
10        return ans;
11    }
12};