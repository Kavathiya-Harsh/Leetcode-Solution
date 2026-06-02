// Last updated: 6/2/2026, 9:46:17 AM
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n<=0) return false;
        return (n & (n-1)) == 0;
    }
};