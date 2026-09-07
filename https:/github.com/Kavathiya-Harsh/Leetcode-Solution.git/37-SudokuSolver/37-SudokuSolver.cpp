// Last updated: 9/7/2026, 1:45:16 PM
class Solution {
public:
    bool solve(vector<vector<char>>& b) {
        for(int r=0;r<9;r++)
            for(int c=0;c<9;c++)
                if(b[r][c]=='.') {
                    for(char x='1';x<='9';x++) {
                        if(ok(b,r,c,x)) {
                            b[r][c]=x;
                            if(solve(b)) return true;
                            b[r][c]='.';
                        }
                    }
                    return false;
                }
        return true;
    }

    bool ok(vector<vector<char>>& b,int r,int c,char x) {
        for(int i=0;i<9;i++)
            if(b[r][i]==x || b[i][c]==x ||
               b[3*(r/3)+i/3][3*(c/3)+i%3]==x)
                return false;
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};