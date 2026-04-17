// Last updated: 17/04/2026, 09:30:52
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        string subString = strs[0];

        for(int i = 1; i < strs.size(); ++i) {
            while(strs[i].find(subString) != 0) {
                subString.pop_back();

                if(subString.empty()) return "";
            }
        }

        return subString;
    }
};