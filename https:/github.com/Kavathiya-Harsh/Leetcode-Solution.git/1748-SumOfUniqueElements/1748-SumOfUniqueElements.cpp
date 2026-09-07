// Last updated: 9/7/2026, 1:41:46 PM
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int freq[101] = {0};
        
        // Count frequency
        for (int x : nums) {
            freq[x]++;
        }
        
        // Sum unique elements
        int sum = 0;
        for (int i = 1; i <= 100; i++) {
            if (freq[i] == 1) {
                sum += i;
            }
        }
        
        return sum;
    }
};