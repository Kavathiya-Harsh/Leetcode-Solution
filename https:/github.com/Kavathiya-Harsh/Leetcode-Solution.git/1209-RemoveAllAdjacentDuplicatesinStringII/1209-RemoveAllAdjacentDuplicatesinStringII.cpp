// Last updated: 6/6/2026, 11:50:27 AM
1class Solution {
2public:
3    string removeDuplicates(string s, int k) {
4        vector<pair<char, int>> st;
5
6        for (char ch : s) {
7            if (!st.empty() && st.back().first == ch) {
8                st.back().second++;
9
10                if (st.back().second == k)
11                    st.pop_back();
12            } else {
13                st.push_back({ch, 1});
14            }
15        }
16
17        string ans;
18
19        for (auto &[ch, cnt] : st)
20            ans.append(cnt, ch);
21
22        return ans;
23    }
24};