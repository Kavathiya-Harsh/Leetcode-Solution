// Last updated: 9/7/2026, 1:41:31 PM
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