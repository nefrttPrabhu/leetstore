class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int>& vis, int node){
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[node] = 1;
                dfs(adj, vis, it);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& a) {
        int l = a.size();
        vector<vector<int>> adj(l);
        vector<int> vis(l,0);
        int cnt = 0;

        for(int i = 0;i < l; i++){
            for(int j = 0;j < l; j++){
                if(a[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }

        for(int i = 0 ;i < l; i++){
            if(!vis[i]){
                dfs(adj,vis,i);
                cnt++;
            }
        }
        return cnt;
    }
};