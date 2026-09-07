// Last updated: 9/7/2026, 1:42:31 PM
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& a) {
        unordered_map<int,int> m;

        for(auto x : a)
            if(x[1] >= 2 && x[1] <= 9)
                m[x[0]] |= 1 << x[1];

        int ans = 2 * (n - m.size());

        for(auto [r, x] : m) {
            bool l = !(x & 60);    // 2-5
            bool mid = !(x & 240); // 4-7
            bool rr = !(x & 960);  // 6-9

            if(l && rr) ans += 2;
            else if(l || mid || rr) ans++;
        }

        return ans;
    }
};