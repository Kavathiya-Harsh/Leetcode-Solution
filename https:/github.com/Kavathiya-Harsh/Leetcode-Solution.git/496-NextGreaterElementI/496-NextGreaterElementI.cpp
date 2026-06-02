// Last updated: 6/2/2026, 12:04:15 PM
1class Solution {
2public:
3    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
4
5        vector<int> ans;
6
7        for (int x : nums1) {
8
9            int i = 0;
10
11            while (nums2[i] != x) {
12                i++;
13            }
14
15            int next = -1;
16
17            for (int j = i + 1; j < nums2.size(); j++) {
18
19                if (nums2[j] > x) {
20
21                    next = nums2[j];
22                    break;
23                }
24            }
25
26            ans.push_back(next);
27        }
28
29        return ans;
30    }
31};