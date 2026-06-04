// Last updated: 6/4/2026, 10:32:32 AM
1class Solution {
2public:
3    bool containsDuplicate(vector<int>& nums) {
4        unordered_set<int> st;
5
6        for (int num : nums) {
7            if (st.count(num))
8                return true;
9            st.insert(num);
10        }
11
12        return false;
13    }
14};