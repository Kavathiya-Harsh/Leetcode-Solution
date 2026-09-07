// Last updated: 9/7/2026, 1:41:40 PM
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int col = coordinates[0] - 'a' +1;
        int row = coordinates[1] - '0';

        return(row+col) % 2 ==1;
    }
};