// Last updated: 6/2/2026, 9:45:38 AM
class Solution {
public:
    bool isSameAfterReversals(int num) {
        if(num == 0) return true;
        return num%10 != 0;
    }
};