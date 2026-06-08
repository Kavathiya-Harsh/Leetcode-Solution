// Last updated: 6/8/2026, 8:56:01 AM
1class Solution {
2public:
3    vector<int> pivotArray(vector<int>& nums, int pivot) {
4        vector<int> less, equal, greater;
5
6        for (int num : nums) {
7            if (num < pivot) {
8                less.push_back(num);
9            }
10            else if (num == pivot) {
11                equal.push_back(num);
12            }
13            else {
14                greater.push_back(num);
15            }
16        }
17
18        less.insert(less.end(), equal.begin(), equal.end());
19        less.insert(less.end(), greater.begin(), greater.end());
20
21        return less;
22    }
23};