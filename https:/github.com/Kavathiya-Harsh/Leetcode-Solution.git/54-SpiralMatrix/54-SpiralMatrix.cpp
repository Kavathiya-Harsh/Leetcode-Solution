// Last updated: 9/7/2026, 1:45:07 PM
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        vector<int> ans;
        int t = 0, b = a.size() - 1;
        int l = 0, r = a[0].size() - 1;

        while (t <= b && l <= r) {
            for (int i = l; i <= r; i++) ans.push_back(a[t][i]);
            t++;

            for (int i = t; i <= b; i++) ans.push_back(a[i][r]);
            r--;

            if (t <= b)
                for (int i = r; i >= l; i--) ans.push_back(a[b][i]);
            b--;

            if (l <= r)
                for (int i = b; i >= t; i--) ans.push_back(a[i][l]);
            l++;
        }

        return ans;
    }
};