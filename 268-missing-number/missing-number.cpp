// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         for(int i = 0;i < nums.size(); i++){
//             if(nums[i]==i){
//                 continue;
//             }
//             else{
//                 return i;
//             }
//         }
//         return nums.size();
//     }
// };




// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n = nums.size();
//         int s1 = n * (n + 1) / 2;
//         int s2 = 0;

//         for(int i = 0; i < n; i++){
//             s2 = s2 + nums[i];
//         }
//         return s1 - s2;
//     }
// };




/*
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int XOR_one_To_n, N = nums.size();
        // Find XOR of 0 to N
        if (N % 4 == 1) XOR_one_To_n = 1;
        else if (N % 4 == 2) XOR_one_To_n = 3;
        else if (N % 4 == 3) XOR_one_To_n = 0;
        else if (N % 4 == 4) XOR_one_To_n = 4;
        // Find XOR of the given numbers in nums
        int XOR_given_nums = 0;
        for (auto& num : nums) {
            XOR_given_nums ^= num;
        }
        // Make XOR of XOR_one_To_n and XOR_given_nums
        return XOR_one_To_n ^ XOR_given_nums;
    }
};
*/


/*
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            if(nums[0] == 1) return 0;
            else return 1;
        }
        sort(nums.begin() , nums.end());
        if(nums[0] != 0) return 0;
        for(int i = 0; i < n-1 ; i++){
            if((nums[i+1] - nums[i])> 1 ){
                return i+1;
                break;
            }
        }
        return n;
    }
};
*/



class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i <= n; i++){
            int c = 0;
            for(int j = 0; j < n; j++){
                if(nums[j] == i){
                    c = 1;
                    break;
                }
            }
            if(!c){
                return i;
            }
        }
        return 0;
    }
};
