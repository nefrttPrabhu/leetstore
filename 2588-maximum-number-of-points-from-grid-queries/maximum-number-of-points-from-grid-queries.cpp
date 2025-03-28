class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        int totalCells = m * n;
        vector<int> answer(queries.size(), 0);

        // Sort queries with indices to restore original order later
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); ++i) {
            sortedQueries.emplace_back(queries[i], i);
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        // Min-heap for BFS expansion
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int> directions = {-1, 0, 1, 0, -1};

        // Start BFS from (0,0)
        minHeap.emplace(grid[0][0], make_pair(0, 0));
        visited[0][0] = true;

        int processedCells = 0; // Number of reachable cells for a query
        int lastQueryPoints = 0; // Store last processed points

        for (auto& [queryValue, originalIndex] : sortedQueries) {
            // Process heap while grid values are smaller than query
            while (!minHeap.empty() && minHeap.top().first < queryValue) {
                auto [cellValue, pos] = minHeap.top();
                minHeap.pop();
                int x = pos.first, y = pos.second;
                
                processedCells++; // We gain a point for this cell

                // Expand to neighbors
                for (int d = 0; d < 4; ++d) {
                    int nx = x + directions[d], ny = y + directions[d + 1];
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        minHeap.emplace(grid[nx][ny], make_pair(nx, ny));
                    }
                }
            }
            answer[originalIndex] = processedCells; // Store answer for this query
        }

        return answer;
    }
};
