// Last updated: 6/2/2026, 9:46:41 AM
class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindrome
        // Numbers ending with 0 (but not 0 itself) are also not palindrome
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;

        // Reverse half of the number
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // For even digits: x == reversedHalf
        // For odd digits: x == reversedHalf / 10
        return (x == reversedHalf || x == reversedHalf / 10);
    }
};