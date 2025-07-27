class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int>ng(n);
        vector<int>pg(n);

        pg[0] = height[0];
        for(int i = 1; i < n; i++){
            pg[i] = max(height[i], pg[i - 1]);
        }

        ng[height.size() - 1] = height[height.size() - 1];
        for(int i = n - 2; i >= 0; i--){
            ng[i] = max(height[i], ng[i + 1]);
        }

        int water = 0;
        for(int i = 0; i < n; i++){
            water += min(ng[i], pg[i]) - height[i];
        }
        return water;
    }
};