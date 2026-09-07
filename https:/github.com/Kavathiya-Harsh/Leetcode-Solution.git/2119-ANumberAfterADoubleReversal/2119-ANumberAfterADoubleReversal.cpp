// Last updated: 9/7/2026, 1:40:50 PM
class Solution {
public:
    bool isSameAfterReversals(int num) {
        if(num == 0) return true;
        return num%10 != 0;
    }
};