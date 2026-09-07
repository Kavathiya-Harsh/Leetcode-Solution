// Last updated: 9/7/2026, 1:44:15 PM
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0, n = words.size();
        vector<int> mask(n);

        for (int i = 0; i < n; i++)
            for (char c : words[i])
                mask[i] |= 1 << (c - 'a');

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if ((mask[i] & mask[j]) == 0)
                    ans = max(ans, (int)words[i].size() * (int)words[j].size());

        return ans;
    }
};