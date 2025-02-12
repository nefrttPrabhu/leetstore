class Solution {
public:
    int sumofdigit(int n){
        int sum = 0;
        while(n != 0){
            sum += n % 10;
            n = n / 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map <int, int> mp;
        int maxsum = -1;

        for(int n : nums){
            int sum = sumofdigit(n);

            if(mp.find(sum) != mp.end()){
                maxsum = max(maxsum, n + mp[sum]);
            }

            mp[sum] = max(n, mp[sum]);
        }
        return maxsum;
    }

};