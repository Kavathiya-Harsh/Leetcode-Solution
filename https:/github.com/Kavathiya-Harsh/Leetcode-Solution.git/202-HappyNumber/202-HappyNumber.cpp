// Last updated: 6/8/2026, 9:06:59 PM
1class Solution {
2public:
3    int getNext(int n) {
4        int sum = 0;
5
6        while (n > 0) {
7            int digit = n % 10;
8            sum += digit * digit;
9            n /= 10;
10        }
11
12        return sum;
13    }
14
15    bool isHappy(int n) {
16        unordered_set<int> seen;
17
18        while (n != 1 && !seen.count(n)) {
19            seen.insert(n);
20            n = getNext(n);
21        }
22
23        return n == 1;
24    }
25};