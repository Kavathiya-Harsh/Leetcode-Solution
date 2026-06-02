// Last updated: 6/2/2026, 9:45:46 AM
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