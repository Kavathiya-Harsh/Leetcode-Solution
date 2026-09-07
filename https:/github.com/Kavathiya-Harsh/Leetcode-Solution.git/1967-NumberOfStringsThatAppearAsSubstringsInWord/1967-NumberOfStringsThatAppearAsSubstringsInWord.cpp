// Last updated: 9/7/2026, 1:41:12 PM
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