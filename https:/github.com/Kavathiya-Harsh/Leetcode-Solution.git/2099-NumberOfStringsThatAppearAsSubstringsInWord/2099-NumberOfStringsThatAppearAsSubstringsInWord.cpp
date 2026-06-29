// Last updated: 6/29/2026, 8:46:15 AM
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        
        for (string &p : patterns) {
            if (word.find(p) != string::npos) {
                count++;
            }
        }
        
        return count;
    }
};