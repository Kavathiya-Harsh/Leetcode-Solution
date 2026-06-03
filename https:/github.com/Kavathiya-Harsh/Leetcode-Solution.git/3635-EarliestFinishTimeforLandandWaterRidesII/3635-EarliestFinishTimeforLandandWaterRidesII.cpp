// Last updated: 6/3/2026, 10:59:24 AM
1class Solution {
2public:
3    
4    long long solve(vector<int>& startA, vector<int>& durA,
5                    vector<int>& startB, vector<int>& durB) {
6        
7        int m = startB.size();
8
9        vector<pair<int,int>> rides;
10        for (int i = 0; i < m; i++) {
11            rides.push_back({startB[i], durB[i]});
12        }
13
14        sort(rides.begin(), rides.end());
15
16        vector<int> starts(m);
17
18        vector<long long> prefMinDur(m);
19        vector<long long> sufMinOpenFinish(m);
20
21        for (int i = 0; i < m; i++) {
22            starts[i] = rides[i].first;
23        }
24
25        prefMinDur[0] = rides[0].second;
26        for (int i = 1; i < m; i++) {
27            prefMinDur[i] =
28                min(prefMinDur[i - 1], (long long)rides[i].second);
29        }
30
31        sufMinOpenFinish[m - 1] =
32            (long long)rides[m - 1].first + rides[m - 1].second;
33
34        for (int i = m - 2; i >= 0; i--) {
35            sufMinOpenFinish[i] =
36                min(sufMinOpenFinish[i + 1],
37                    (long long)rides[i].first + rides[i].second);
38        }
39
40        long long ans = LLONG_MAX;
41
42        for (int i = 0; i < startA.size(); i++) {
43
44            long long finishA =
45                (long long)startA[i] + durA[i];
46
47            int pos =
48                upper_bound(starts.begin(), starts.end(), finishA)
49                - starts.begin() - 1;
50
51            if (pos >= 0) {
52                ans = min(ans,
53                          finishA + prefMinDur[pos]);
54            }
55
56            if (pos + 1 < m) {
57                ans = min(ans,
58                          sufMinOpenFinish[pos + 1]);
59            }
60        }
61
62        return ans;
63    }
64
65    int earliestFinishTime(vector<int>& landStartTime,
66                           vector<int>& landDuration,
67                           vector<int>& waterStartTime,
68                           vector<int>& waterDuration) {
69
70        long long ans1 =
71            solve(landStartTime, landDuration,
72                  waterStartTime, waterDuration);
73
74        long long ans2 =
75            solve(waterStartTime, waterDuration,
76                  landStartTime, landDuration);
77
78        return (int)min(ans1, ans2);
79    }
80};