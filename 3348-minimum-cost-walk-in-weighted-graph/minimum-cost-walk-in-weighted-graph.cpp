
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<unordered_map<int, int>> graph(n);
        
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (graph[u].count(v)) {
                graph[u][v] &= w;
                graph[v][u] &= w;
            } else {
                graph[u][v] = w;
                graph[v][u] = w;
            }
        }

        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        
        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : (parent[x] = find(parent[x]));
        };
        
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            int pu = find(u), pv = find(v);
            if (pu != pv) parent[pu] = pv;
        }

        unordered_map<int, int> componentMinCost;
        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int root = find(i);
                queue<int> q;
                q.push(i);
                visited[i] = true;
                int minCost = INT_MAX;
                
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    
                    for (auto& [neighbor, weight] : graph[node]) {
                        minCost &= weight;
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
                
                componentMinCost[root] = minCost;
            }
        }

        vector<int> result;
        for (auto& q : query) {
            int s = q[0], t = q[1];
            if (find(s) != find(t)) {
                result.push_back(-1);
            } else {
                result.push_back(componentMinCost[find(s)]);
            }
        }
        
        return result;
    }
};






/*

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<unordered_map<int, int>> graph(n);
        
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (graph[u].count(v)) {
                graph[u][v] &= w;
                graph[v][u] &= w;
            } else {
                graph[u][v] = w;
                graph[v][u] = w;
            }
        }

        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        
        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : (parent[x] = find(parent[x]));
        };
        
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            int pu = find(u), pv = find(v);
            if (pu != pv) parent[pu] = pv;
        }

        unordered_map<int, int> componentMinCost;
        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int root = find(i);
                queue<int> q;
                q.push(i);
                visited[i] = true;
                int minCost = INT_MAX;
                
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    
                    for (auto& [neighbor, weight] : graph[node]) {
                        minCost &= weight;
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
                
                componentMinCost[root] = minCost;
            }
        }

        vector<int> result;
        for (auto& q : query) {
            int s = q[0], t = q[1];
            if (find(s) != find(t)) {
                result.push_back(-1);
            } else {
                result.push_back(componentMinCost[find(s)]);
            }
        }
        
        return result;
    }
};
*/