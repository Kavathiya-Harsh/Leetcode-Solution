// Last updated: 11/04/2026, 14:23:46
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size() - 1;

        while(i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};