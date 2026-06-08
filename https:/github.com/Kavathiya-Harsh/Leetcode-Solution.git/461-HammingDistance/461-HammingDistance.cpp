// Last updated: 6/8/2026, 9:18:21 PM
1class Solution {
2public:
3    int hammingDistance(int x, int y) {
4
5        int diff = x ^ y;
6        int count = 0;
7
8        while(diff) {
9            count += diff & 1;
10            diff >>= 1;
11        }
12
13        return count;
14    }
15};