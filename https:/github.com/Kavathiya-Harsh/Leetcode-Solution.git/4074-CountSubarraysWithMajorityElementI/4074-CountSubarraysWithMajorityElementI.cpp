// Last updated: 6/29/2026, 8:45:44 AM
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        
        // prefix sum
        vector<int> prefix(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == target)
                prefix[i + 1] = prefix[i] + 1;
            else
                prefix[i + 1] = prefix[i] - 1;
        }
        
        // multiset to maintain sorted prefix sums
        multiset<int> st;
        int ans = 0;
        
        for (int i = 0; i <= n; i++) {
            // count how many prefix values are smaller
            ans += distance(st.begin(), st.lower_bound(prefix[i]));
            st.insert(prefix[i]);
        }
        
        return ans;
    }
};