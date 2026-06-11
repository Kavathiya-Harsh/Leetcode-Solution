// Last updated: 6/11/2026, 8:12:50 AM
class Solution {
public:
    int strStr(string haystack, string needle) {
        int pos = haystack.find(needle);
        return pos == string::npos ? -1 : pos;
    }
};