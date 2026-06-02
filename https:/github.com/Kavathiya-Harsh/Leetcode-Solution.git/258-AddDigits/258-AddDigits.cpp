// Last updated: 6/2/2026, 9:46:13 AM
class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {  // run until single digit
            int sum = 0;

            while (num > 0) {
                sum += num % 10;  // get last digit
                num /= 10;        // remove last digit
            }

            num = sum; // update number
        }

        return num;
    }
};