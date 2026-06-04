// Last updated: 6/4/2026, 11:14:37 AM
1class Solution {
2public:
3    int strStr(string haystack, string needle) {
4        int pos = haystack.find(needle);
5        return pos == string::npos ? -1 : pos;
6    }
7};