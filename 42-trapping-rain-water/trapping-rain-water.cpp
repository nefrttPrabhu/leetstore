class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>pg(height.size(),0);
        vector<int>ng(height.size(),0);
        int n = height.size();

        pg[0] = height[0];
        for(int i = 1; i < n; i++){
            pg[i] = max(pg[i - 1], height[i]);
        }

        ng[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; i--){
            ng[i] = max(ng[i + 1], height[i]);
        }

        int water = 0;

        for(int i = 0; i < n; i++){
            water += (min(pg[i],ng[i]) - height[i]);
        }
        return water;
    }
};