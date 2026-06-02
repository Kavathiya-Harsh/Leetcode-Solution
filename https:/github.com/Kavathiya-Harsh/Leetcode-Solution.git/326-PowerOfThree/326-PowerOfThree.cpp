// Last updated: 6/2/2026, 9:46:10 AM
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;

        while(n%3 == 0)
        {
            n/=3;
        }
        return n==1;
    }
};