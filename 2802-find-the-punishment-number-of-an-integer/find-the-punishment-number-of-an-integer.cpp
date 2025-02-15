class Solution {
public:
    bool isValidPartition(string s, int target, int index, int sum) {
        if (index == s.size()) {
            return sum == target;
        }
        
        int num = 0;
        for (int i = index; i < s.size(); i++) {
            num = num * 10 + (s[i] - '0');
            if (num + sum <= target && isValidPartition(s, target, i + 1, sum + num)) {
                return true;
            }
        }
        
        return false;
    }
    
    int punishmentNumber(int n) {
        int totalSum = 0;
        
        for (int i = 1; i <= n; i++) {
            int square = i * i;
            string squareStr = to_string(square);
            if (isValidPartition(squareStr, i, 0, 0)) {
                totalSum += square;
            }
        }
        
        return totalSum;
    }
};
