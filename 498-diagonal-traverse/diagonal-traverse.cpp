class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int siz = m + n - 1;

        vector<vector<int>> temp(siz);
        vector<int> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                temp[i + j].push_back(mat[i][j]);
            }
        }

        for (int i = 0; i < siz; i++) {
            if (i % 2 == 0) {
                reverse(temp[i].begin(), temp[i].end());
            }
            for (int val : temp[i]) {
                ans.push_back(val);
            }
        }

        return ans;
    }
};

        // for(int i = 0; i < siz; i++){
        //     int maxi = siz / 2;
        //     if(i <= maxi){
        //         int c = 0;
        //         for(int j = 0; j <= i; j++){
        //             ans.push_back(mat[i - c][c]);
        //             c++;
        //         }
        //     }
        //     else{
        //         int t = i - maxi;
        //         ans.push_back(mat[maxi][t])
        //     }
        // }

        
//     }
// };