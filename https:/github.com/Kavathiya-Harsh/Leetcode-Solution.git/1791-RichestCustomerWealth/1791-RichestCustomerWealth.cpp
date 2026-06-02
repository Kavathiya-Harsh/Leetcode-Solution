// Last updated: 6/2/2026, 9:45:48 AM
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;

        for (auto row : accounts){
          ans = max(ans, accumulate(row.begin(), row.end(),0));
        }
        return ans;
    }
};