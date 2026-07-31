// Last updated: 7/31/2026, 1:29:15 PM
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        stringstream ss(path);
        string part;

        while (getline(ss, part, '/')) {
            if (part == "" || part == ".") continue;
            else if (part == "..") {
                if (!st.empty()) st.pop_back();
            } 
            else {
                st.push_back(part);
            }
        }

        string ans = "";
        for (string dir : st) {
            ans += "/" + dir;
        }

        return ans.empty() ? "/" : ans;
    }
};