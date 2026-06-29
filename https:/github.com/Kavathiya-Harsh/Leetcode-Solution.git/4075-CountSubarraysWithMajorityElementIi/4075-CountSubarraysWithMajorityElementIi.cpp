// Last updated: 6/29/2026, 8:45:46 AM
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        // Step 1: Transform to +1 / -1
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = (nums[i] == target) ? 1 : -1;
        }

        // Step 2: Prefix sum
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }

        // Step 3: Coordinate Compression
        vector<long long> comp = prefix;
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());

        // Fenwick Tree (BIT)
        vector<int> bit(comp.size() + 1, 0);

        auto update = [&](int i) {
            for (i++; i < bit.size(); i += i & -i)
                bit[i]++;
        };

        auto query = [&](int i) {
            int s = 0;
            for (i++; i > 0; i -= i & -i)
                s += bit[i];
            return s;
        };

        long long ans = 0;

        // Step 4: Count valid subarrays
        for (auto x : prefix) {
            int idx = lower_bound(comp.begin(), comp.end(), x) - comp.begin();

            // count how many prefix < current
            if (idx > 0)
                ans += query(idx - 1);

            update(idx);
        }

        return ans;
    }
};