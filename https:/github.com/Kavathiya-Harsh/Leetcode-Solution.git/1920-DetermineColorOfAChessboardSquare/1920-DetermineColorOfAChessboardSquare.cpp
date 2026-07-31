// Last updated: 7/31/2026, 1:26:53 PM
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int col = coordinates[0] - 'a' +1;
        int row = coordinates[1] - '0';

        return(row+col) % 2 ==1;
    }
};