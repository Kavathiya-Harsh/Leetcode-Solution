// Last updated: 6/29/2026, 8:46:21 AM
class Solution {
public:
    bool checkIfPangram(string sentence) {

        set<char> st;

        for (char ch : sentence) {
            st.insert(ch);
        }

        return st.size() == 26;
    }
};