class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);

        // Build adjacency list
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int completeComponents = 0;

        // DFS to find connected components
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, adj, visited, component);

                // Check if the component forms a complete graph
                if (isComplete(component, adj)) {
                    completeComponents++;
                }
            }
        }

        return completeComponents;
    }

private:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& component) {
        visited[node] = true;
        component.push_back(node);

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, component);
            }
        }
    }

    bool isComplete(vector<int>& component, vector<vector<int>>& adj) {
        int size = component.size();
        for (int node : component) {
            if (adj[node].size() != size - 1) {
                return false;
            }
        }
        return true;
    }
};
