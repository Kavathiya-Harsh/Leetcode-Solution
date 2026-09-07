// Last updated: 9/7/2026, 1:41:39 PM
class Solution {
public:
    string truncateSentence(string s, int k) {
        int count = 0;

        for (int i = 0;i< s.size();i++){
          if (s[i] == ' '){
            count++;
          }
          if (count == k ){
            return s.substr(0,i);
          }
        }
        return s; 
    }
};