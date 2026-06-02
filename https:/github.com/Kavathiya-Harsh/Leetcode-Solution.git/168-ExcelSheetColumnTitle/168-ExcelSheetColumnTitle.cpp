// Last updated: 6/2/2026, 9:46:23 AM
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";

        while (columnNumber > 0) {
            columnNumber--;

            char ch = 'A' + (columnNumber % 26);
            result = ch + result;

            columnNumber /= 26;
        }
        return result;
    }
};