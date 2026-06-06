// Last updated: 6/6/2026, 10:53:37 AM
1class Solution {
2public:
3    vector<int> leftRightDifference(vector<int>& nums) {
4        int totalSum = accumulate(nums.begin(), nums.end(), 0);
5        int leftSum = 0;
6        vector<int> ans;
7
8        for (int num : nums) {
9            totalSum -= num; // rightSum
10            ans.push_back(abs(leftSum - totalSum));
11            leftSum += num;
12        }
13
14        return ans;
15    }
16};