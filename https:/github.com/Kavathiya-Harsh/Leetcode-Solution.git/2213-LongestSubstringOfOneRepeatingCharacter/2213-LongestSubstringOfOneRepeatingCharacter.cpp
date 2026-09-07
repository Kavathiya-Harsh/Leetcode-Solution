// Last updated: 9/7/2026, 1:40:40 PM
class Solution {
public:
    vector<int> longestRepeating(string s, string qc, vector<int>& qi) {
        int n = s.size();
        
        set<pair<int,int>> st;
        multiset<int> ms;

        // Create initial same-character intervals
        for (int i = 0; i < n; ) {
            int j = i;
            while (j + 1 < n && s[j] == s[j + 1]) j++;
            
            st.insert({i, j});
            ms.insert(j - i + 1);
            i = j + 1;
        }

        vector<int> ans;

        for (int q = 0; q < qi.size(); q++) {
            int p = qi[q];
            char c = qc[q];

            if (s[p] != c) {
                auto it = st.upper_bound({p, n});
                --it;

                int l = it->first, r = it->second;
                ms.erase(ms.find(r - l + 1));
                st.erase(it);

                if (l < p) {
                    st.insert({l, p - 1});
                    ms.insert(p - l);
                }

                if (p < r) {
                    st.insert({p + 1, r});
                    ms.insert(r - p);
                }

                s[p] = c;

                int L = p, R = p;

                auto nxt = st.lower_bound({p + 1, 0});
                if (nxt != st.end() && nxt->first == p + 1 &&
                    s[nxt->first] == c) {
                    R = nxt->second;
                    ms.erase(ms.find(nxt->second - nxt->first + 1));
                    st.erase(nxt);
                }

                auto prv = st.lower_bound({p, 0});
                if (prv != st.begin()) {
                    --prv;
                    if (prv->second == p - 1 && s[prv->first] == c) {
                        L = prv->first;
                        ms.erase(ms.find(prv->second - prv->first + 1));
                        st.erase(prv);
                    }
                }

                st.insert({L, R});
                ms.insert(R - L + 1);
            }

            ans.push_back(*ms.rbegin());
        }

        return ans;
    }
};