// Last updated: 7/28/2026, 1:37:34 PM
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<pair<int,int>> dq;

        // Start from (0,0)
        dist[0][0] = grid[0][0];
        dq.push_front({0, 0});

        vector<int> dir = {0, 1, 0, -1, 0};

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (int k = 0; k < 4; k++) {
                int nx = x + dir[k];
                int ny = y + dir[k + 1];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    int cost = grid[nx][ny];
                    
                    if (dist[x][y] + cost < dist[nx][ny]) {
                        dist[nx][ny] = dist[x][y] + cost;

                        if (cost == 0)
                            dq.push_front({nx, ny});
                        else
                            dq.push_back({nx, ny});
                    }
                }
            }
        }

        // Check if remaining health >= 1
        return dist[m-1][n-1] < health;
    }
};