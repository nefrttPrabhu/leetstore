class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>pg(height.size(),0);
        vector<int>ng(height.size(),0);

        //prev greater
        pg[0] = height[0];
        for(int i = 1; i < height.size(); i++){
            pg[i] = max(pg[i - 1], height[i]);
        }

        //next greater 
        ng[height.size() - 1] = height[height.size() - 1];
        for(int i = height.size() - 2; i >= 0; i--){
            ng[i] = max(ng[i + 1], height[i]);
        }

        //water
        int sum = 0;
        for(int i = 0; i < height.size(); i++){
            sum += min(pg[i],ng[i]) - height[i];
        }

        return sum;
    }
};