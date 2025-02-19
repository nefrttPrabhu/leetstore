#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 0) return 0;

        sort(points.begin(), points.end());

        int c = 1; 
        vector<int> prev = points[0];

        for (int i = 1; i < n; i++) { 
            int currsp = points[i][0];
            int currep = points[i][1];

            int prevsp = prev[0];
            int prevep = prev[1];

            if (currsp > prevep) {  // No overlap, so we need another arrow
                c++;
                prev = points[i];
            } 
            
            else {  // Overlapping interval, adjust the range
                prev[0] = max(currsp, prevsp);
                prev[1] = min(currep, prevep);
            }
        }

        return c;
    }
};
