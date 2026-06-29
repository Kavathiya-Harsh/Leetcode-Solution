// Last updated: 6/29/2026, 8:46:25 AM
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