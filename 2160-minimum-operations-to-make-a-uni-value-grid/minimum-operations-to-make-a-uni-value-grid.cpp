class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> values;
        int m = grid.size(), n = grid[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                values.push_back(grid[i][j]);
            }
        }
        
        int remainder = values[0] % x;
        for (int num : values) {
            if (num % x != remainder) return -1;
        }
        
        sort(values.begin(), values.end());
        
        int median = values[values.size() / 2];
        
        int operations = 0;
        for (int num : values) {
            operations += abs(num - median) / x;
        }
        
        return operations;
    }
};
