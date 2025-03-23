class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);
        
        for (auto& road : roads) {
            int u = road[0], v = road[1], t = road[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        
        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;
        
        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();
            
            if (time > dist[node]) continue;
            
            for (auto& [neighbor, travelTime] : adj[node]) {
                long long newTime = time + travelTime;
                
                if (newTime < dist[neighbor]) {
                    dist[neighbor] = newTime;
                    pq.push({newTime, neighbor});
                    ways[neighbor] = ways[node];
                } else if (newTime == dist[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }
        
        return ways[n - 1];
    }
};
