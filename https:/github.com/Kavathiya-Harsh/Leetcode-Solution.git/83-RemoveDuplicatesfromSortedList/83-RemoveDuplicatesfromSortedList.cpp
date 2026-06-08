// Last updated: 6/8/2026, 9:11:00 PM
1class Solution {
2public:
3    void merge(vector<int>& nums1, int m,vector<int>& nums2, int n) {
4
5        for(int i = 0; i < n; i++) {
6            nums1[m + i] = nums2[i];
7        }
8
9        sort(nums1.begin(), nums1.end());
10    }
11};