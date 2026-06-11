// Last updated: 6/11/2026, 8:11:47 AM
class Solution {
public:
    
    long long solve(vector<int>& startA, vector<int>& durA,
                    vector<int>& startB, vector<int>& durB) {
        
        int m = startB.size();

        vector<pair<int,int>> rides;
        for (int i = 0; i < m; i++) {
            rides.push_back({startB[i], durB[i]});
        }

        sort(rides.begin(), rides.end());

        vector<int> starts(m);

        vector<long long> prefMinDur(m);
        vector<long long> sufMinOpenFinish(m);

        for (int i = 0; i < m; i++) {
            starts[i] = rides[i].first;
        }

        prefMinDur[0] = rides[0].second;
        for (int i = 1; i < m; i++) {
            prefMinDur[i] =
                min(prefMinDur[i - 1], (long long)rides[i].second);
        }

        sufMinOpenFinish[m - 1] =
            (long long)rides[m - 1].first + rides[m - 1].second;

        for (int i = m - 2; i >= 0; i--) {
            sufMinOpenFinish[i] =
                min(sufMinOpenFinish[i + 1],
                    (long long)rides[i].first + rides[i].second);
        }

        long long ans = LLONG_MAX;

        for (int i = 0; i < startA.size(); i++) {

            long long finishA =
                (long long)startA[i] + durA[i];

            int pos =
                upper_bound(starts.begin(), starts.end(), finishA)
                - starts.begin() - 1;

            if (pos >= 0) {
                ans = min(ans,
                          finishA + prefMinDur[pos]);
            }

            if (pos + 1 < m) {
                ans = min(ans,
                          sufMinOpenFinish[pos + 1]);
            }
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        long long ans1 =
            solve(landStartTime, landDuration,
                  waterStartTime, waterDuration);

        long long ans2 =
            solve(waterStartTime, waterDuration,
                  landStartTime, landDuration);

        return (int)min(ans1, ans2);
    }
};