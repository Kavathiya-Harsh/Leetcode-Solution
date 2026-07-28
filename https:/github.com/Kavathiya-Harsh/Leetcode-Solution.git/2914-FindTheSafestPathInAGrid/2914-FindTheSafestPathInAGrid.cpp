// Last updated: 7/28/2026, 1:37:36 PM
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        queue<pair<int,int>> q;

        // Step 1: Multi-source BFS (distance from thief)
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        vector<int> d = {0,1,0,-1,0};
        while(!q.empty()){
            auto [r,c]=q.front(); q.pop();
            for(int k=0;k<4;k++){
                int nr=r+d[k], nc=c+d[k+1];
                if(nr>=0 && nc>=0 && nr<n && nc<n && dist[nr][nc]>dist[r][c]+1){
                    dist[nr][nc]=dist[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }

        // Step 2: Max-heap (greedy path)
        priority_queue<vector<int>> pq;
        pq.push({dist[0][0],0,0});

        vector<vector<int>> vis(n, vector<int>(n,0));

        while(!pq.empty()){
            auto cur=pq.top(); pq.pop();
            int safe=cur[0], r=cur[1], c=cur[2];

            if(r==n-1 && c==n-1) return safe;
            if(vis[r][c]) continue;
            vis[r][c]=1;

            for(int k=0;k<4;k++){
                int nr=r+d[k], nc=c+d[k+1];
                if(nr>=0 && nc>=0 && nr<n && nc<n && !vis[nr][nc]){
                    pq.push({min(safe, dist[nr][nc]), nr, nc});
                }
            }
        }

        return 0;
    }
};