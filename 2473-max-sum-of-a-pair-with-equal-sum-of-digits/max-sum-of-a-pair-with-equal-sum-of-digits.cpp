class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> maxMap;
        int maxSum = -1;
        
        for (int num : nums) {
            int sumDigits = digitSum(num);
            
            if (maxMap.find(sumDigits) != maxMap.end()) {
                maxSum = max(maxSum, maxMap[sumDigits] + num);
            }
            
            maxMap[sumDigits] = max(maxMap[sumDigits], num);
        }
        
        return maxSum;
    }
};
