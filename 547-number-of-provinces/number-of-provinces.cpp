class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int>& vis, int node){
        vis[node] = 1;

        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(adj, vis, it);
            }
        }
    }


    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        int cnt = 0;
        
        vector<vector<int>> adj(n + 1);
        vector<int> vis(n, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    // adj[j].push_back(isConnected[i]);                
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                cnt++;
                dfs(adj, vis, i);
            }
        }

        return cnt;
    }
};