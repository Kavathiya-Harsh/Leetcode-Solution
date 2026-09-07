// Last updated: 9/7/2026, 1:44:58 PM
class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();
        bool row = false, col = false;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (a[i][j] == 0) {
                    if (i == 0) row = true;
                    if (j == 0) col = true;
                    a[i][0] = a[0][j] = 0;
                }

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (a[i][0] == 0 || a[0][j] == 0)
                    a[i][j] = 0;

        if (row)
            for (int j = 0; j < n; j++) a[0][j] = 0;

        if (col)
            for (int i = 0; i < m; i++) a[i][0] = 0;
    }
};