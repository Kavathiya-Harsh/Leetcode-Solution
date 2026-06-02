// Last updated: 6/2/2026, 9:46:06 AM
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;
        vector<int> result;

        // Count frequency of elements in nums1
        for (int num : nums1) {
            freq[num]++;
        }

        // Check elements in nums2
        for (int num : nums2) {
            if (freq[num] > 0) {
                result.push_back(num);
                freq[num]--;
            }
        }
        return result;
    }
};