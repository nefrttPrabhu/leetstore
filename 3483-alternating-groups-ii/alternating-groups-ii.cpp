class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int count = 0;
        int valid = 1; 
        
        for (int i = 1; i < k; i++) {
            if (colors[i] == colors[i - 1]) {
                valid = 0;
                break;
            }
        }
        count += valid;
        
        for (int i = 1; i < n; i++) {
            int prevIndex = (i - 1) % n;
            int newIndex = (i + k - 1) % n;
            
            if (colors[prevIndex] == colors[(prevIndex + 1) % n]) {
                valid = 1; 
                for (int j = i; j < i + k - 1; j++) {
                    if (colors[j % n] == colors[(j + 1) % n]) {
                        valid = 0;
                        break;
                    }
                }
            } 
            else if (colors[newIndex] == colors[(newIndex - 1 + n) % n]) {
                valid = 0;
            }

            count += valid;
        }
        
        return count;
    }
};
