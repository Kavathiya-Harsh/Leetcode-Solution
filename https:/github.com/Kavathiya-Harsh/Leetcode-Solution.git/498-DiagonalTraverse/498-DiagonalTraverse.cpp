// Last updated: 9/7/2026, 1:43:48 PM
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans;

        for (int s = 0; s < m + n - 1; s++) {
            vector<int> d;

            int r = (s < n) ? 0 : s - n + 1;
            int c = (s < n) ? s : n - 1;

            while (r < m && c >= 0) {
                d.push_back(mat[r++][c--]);
            }

            if (s % 2 == 0) reverse(d.begin(), d.end());
            ans.insert(ans.end(), d.begin(), d.end());
        }

        return ans;
    }
};