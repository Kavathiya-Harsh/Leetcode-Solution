// Last updated: 6/4/2026, 10:52:41 AM
1class Solution {
2public:
3    int pivotInteger(int n) {
4        for (int x = 1; x <= n; x++) {
5            int left = 0, right = 0;
6
7            for (int i = 1; i <= x; i++)
8                left += i;
9
10            for (int i = x; i <= n; i++)
11                right += i;
12
13            if (left == right)
14                return x;
15        }
16
17        return -1;
18    }
19};