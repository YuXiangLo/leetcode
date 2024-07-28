class Solution {
public:
    vector<int> traj_time;

    void dfs(vector<int> adj[], int vis[], int n, int cur, int time, int change, int cost_time) {
        if (vis[cur]) return;
        if (cur == n) {
            traj_time.push_back(cost_time);
            return;
        }
        vis[cur] = true;
        for (int next : adj[cur]) {
            if ((cost_time / change) % 2 == 1) cost_time += change - cost_time % change;
            dfs(adj, vis, n, next, time, change, cost_time + time);
        }
        vis[cur] = false;
    }

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> adj[n+1];
        for (auto &v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        int vis[n+1];
        memset(vis, 0, sizeof(vis));
        dfs(adj, vis, n, 1, time, change, 0);
        for (int i : traj_time) cout << i << ' ';
        return 0;
    }
};
