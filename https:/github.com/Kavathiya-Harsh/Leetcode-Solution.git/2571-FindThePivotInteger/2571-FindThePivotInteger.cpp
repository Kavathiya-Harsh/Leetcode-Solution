// Last updated: 6/11/2026, 8:11:59 AM
class Solution {
public:
    int pivotInteger(int n) {
        for (int x = 1; x <= n; x++) {
            int left = 0, right = 0;

            for (int i = 1; i <= x; i++)
                left += i;

            for (int i = x; i <= n; i++)
                right += i;

            if (left == right)
                return x;
        }

        return -1;
    }
};