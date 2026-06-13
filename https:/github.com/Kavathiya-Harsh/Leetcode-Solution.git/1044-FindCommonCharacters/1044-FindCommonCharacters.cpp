// Last updated: 6/13/2026, 11:51:42 AM
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> res={};

        for(char i : words[0]){
            string temp = "";
            temp+=i;
            bool found = true;
            for(int j =1;j<words.size();j++){
                if(!words[j].contains(i)){
                    found = false;
                    break;
                }
                words[j].erase(words[j].find(i),1);
            }
            if (found){
                res.push_back(temp);
            }
        }
        return res;
    }
};