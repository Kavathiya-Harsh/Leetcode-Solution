// Last updated: 6/15/2026, 9:22:40 AM
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> freq(101, 0);

        // Step 1: Count frequency
        for(int num : nums) {
            freq[num]++;
        }

        // Step 2: Prefix sum
        for(int i = 1; i < 101; i++) {
            freq[i] += freq[i - 1];
        }

        // Step 3: Build result
        vector<int> result;
        for(int num : nums) {
            if(num == 0) {
                result.push_back(0);
            } else {
                result.push_back(freq[num - 1]);
            }
        }

        return result;
    }
};