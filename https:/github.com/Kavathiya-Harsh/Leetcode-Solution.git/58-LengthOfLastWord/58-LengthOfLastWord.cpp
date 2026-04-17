// Last updated: 17/04/2026, 09:30:50
class Solution {
public:
    int lengthOfLastWord(string s) {
      int len = 0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]!= ' '){
                len++;
            }
            else if(len > 0){
                break;
            }
        }
        return len;
    }
};
