class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int>& vis, int node){
        for(auto it: adj[node]){//idhar agar vis[node] = 1 lagate then bus baar baar overwrite karta rehta of the visited nodes coz vis not vis ka check toh neeche rakh he lega
            if(!vis[it]){
                vis[node] = 1;//idhar seedha bus non iterated walon pe 1 update hoga
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
                    adj[j].push_back(i);
                }
            }
        }

        for(int i = 0 ;i < l; i++){
            if(!vis[i]){
                dfs(adj,vis,i);//idhar waiting mai hi jab sare iterations us starting node(provence) ke complete ho gye then fng return ata ie ek province count ho gya 
                cnt++;
            }
        }
        return cnt;
    }
};