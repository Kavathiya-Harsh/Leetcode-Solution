// Last updated: 6/2/2026, 9:46:16 AM
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())return false;

        vector<int>count(26, 0);

        for(char c:s) count[c- 'a']++;
        for(char c:t) count[c-'a']--;

        for(int x : count){
            if(x != 0)return false;
        }
        return true;
    }
};