// Last updated: 6/29/2026, 8:46:23 AM
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int ans = 1;

        for (int i = 1; i < arr.size(); i++) {
            ans = min(arr[i], ans + 1);
        }

        return ans;
    }
};