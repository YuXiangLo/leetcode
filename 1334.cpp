class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int dist[101][101] = {};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = 1e9;
        for (auto &v : edges)
            dist[v[0]][v[1]] = dist[v[1]][v[0]] = v[2];
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    dist[i][j] = dist[j][i] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }

		// So I think I have to edit file to make contribution I guess?
        int ret = -1, ret_cnt = 1e9;
        for (int i = 0, cnt; i < n; i++) {
            cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                cnt += dist[i][j] <= distanceThreshold;
            }

            if (cnt <= ret_cnt) {
                ret_cnt = cnt;
                ret = i;
            }
        }
        return ret;
    }
};
