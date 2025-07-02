class Solution {
public:
    void bfs(vector<vector<int>>& adj, vector<int>& vis, int start) {
        queue<int> q;
        q.push(start);
        vis[start] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                bfs(adj, vis, i);
            }
        }

        return cnt;
    }
};
