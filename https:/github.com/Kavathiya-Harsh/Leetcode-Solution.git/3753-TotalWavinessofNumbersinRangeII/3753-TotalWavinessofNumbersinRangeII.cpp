// Last updated: 6/5/2026, 2:45:25 PM
1class Solution {
2public:
3    struct State {
4        long long count, waviness;
5    };
6
7    string num;
8    State dp[16][11][11];
9    bool vis[16][11][11];
10
11    State dfs(int pos, int prev2, int prev1, bool tight) {
12        if (pos == num.size())
13            return {1, 0};
14
15        if (!tight && vis[pos][prev2][prev1])
16            return dp[pos][prev2][prev1];
17
18        int limit = tight ? num[pos] - '0' : 9;
19
20        State res = {0, 0};
21
22        for (int d = 0; d <= limit; d++) {
23            bool newTight = tight && (d == limit);
24
25            long long add = 0;
26
27            if (prev2 != 10) {
28                if ((prev1 > prev2 && prev1 > d) ||
29                    (prev1 < prev2 && prev1 < d))
30                    add = 1;
31            }
32
33            State nxt = dfs(pos + 1, prev1, d, newTight);
34
35            res.count += nxt.count;
36            res.waviness += nxt.waviness + add * nxt.count;
37        }
38
39        if (!tight) {
40            vis[pos][prev2][prev1] = true;
41            dp[pos][prev2][prev1] = res;
42        }
43
44        return res;
45    }
46
47    long long solve(long long x) {
48        if (x < 100) return 0;
49
50        num = to_string(x);
51
52        memset(vis, 0, sizeof(vis));
53
54        State ans = {0, 0};
55
56        for (int len = 1; len < num.size(); len++) {
57            string old = num;
58            num = string(len, '9');
59
60            memset(vis, 0, sizeof(vis));
61
62            for (int first = 1; first <= 9; first++) {
63                State cur = dfs(1, 10, first, false);
64                ans.waviness += cur.waviness;
65            }
66
67            num = old;
68        }
69
70        memset(vis, 0, sizeof(vis));
71
72        int firstLimit = num[0] - '0';
73
74        for (int first = 1; first <= firstLimit; first++) {
75            State cur = dfs(
76                1,
77                10,
78                first,
79                first == firstLimit
80            );
81
82            ans.waviness += cur.waviness;
83        }
84
85        return ans.waviness;
86    }
87
88    long long totalWaviness(long long num1, long long num2) {
89        return solve(num2) - solve(num1 - 1);
90    }
91};