// Last updated: 17/04/2026, 09:30:47
class Solution {
public:
    bool isIsomorphic(string s, string t) {
      unordered_map<char,int>s1; 
      unordered_map<char,int>t1;
        for(int i=0;i<s.length();++i){
            char ch1=s[i]; char ch2=t[i];
              if(s1.count(ch1) && s1[ch1]!=ch2) return false;
              if(t1.count(ch2) && t1[ch2]!=ch1) return false;
                s1[ch1]=ch2;
                t1[ch2]=ch1;
        } 
      return true;
    }
};