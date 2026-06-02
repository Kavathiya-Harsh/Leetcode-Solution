// Last updated: 6/2/2026, 9:48:12 AM
1class Solution {
2public:
3    int earliestFinishTime(vector<int>& landStartTime,
4                           vector<int>& landDuration,
5                           vector<int>& waterStartTime,
6                           vector<int>& waterDuration) {
7
8        int ans = INT_MAX;
9
10        int n = landStartTime.size();
11        int m = waterStartTime.size();
12
13        for (int i = 0; i < n; i++) {
14            for (int j = 0; j < m; j++) {
15
16                // Land -> Water
17                int landFinish =
18                    landStartTime[i] + landDuration[i];
19
20                int finish1 =
21                    max(landFinish, waterStartTime[j]) +
22                    waterDuration[j];
23
24                // Water -> Land
25                int waterFinish =
26                    waterStartTime[j] + waterDuration[j];
27
28                int finish2 =
29                    max(waterFinish, landStartTime[i]) +
30                    landDuration[i];
31
32                ans = min(ans, min(finish1, finish2));
33            }
34        }
35
36        return ans;
37    }
38};