// class Solution {
// public:
//     bool isValidPartition(string s, int target, int index, int sum) {
//         if (index == s.size()) {
//             return sum == target;
//         }
        
//         int num = 0;
//         for (int i = index; i < s.size(); i++) {
//             num = num * 10 + (s[i] - '0');
//             if (num + sum <= target && isValidPartition(s, target, i + 1, sum + num)) {
//                 return true;
//             }
//         }
        
//         return false;
//     }
    
//     int punishmentNumber(int n) {
//         int totalSum = 0;
        
//         for (int i = 1; i <= n; i++) {
//             int square = i * i;
//             string squareStr = to_string(square);
//             if (isValidPartition(squareStr, i, 0, 0)) {
//                 totalSum += square;
//             }
//         }
        
//         return totalSum;
//     }
// };


/*
class Solution {
    bool checkpartition(int buff, int& i, int sum) {
        if (sum > i) {
            return false;
        }
        if (sum == i && buff==0) {
            return true;
        }
        if (buff == 0) {
            return false;
        }

        int num = 10;
        bool ans = false;
        while ((buff) / num) {
            ans = checkpartition(buff / num, i, sum + (buff % num));
            if(ans){break;}
            num *= 10;
        }

        if(!ans && buff%num){
            ans = checkpartition(buff / num, i, sum + (buff % num));
        }

        return ans;
    }

public:
    int punishmentNumber(int n) {
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            int buff = i * i;

            if (checkpartition(buff, i, 0)) {
                cout << i << endl;
                ans += i * i;
            }
        }

        return ans;
    }
};
*/

class Solution {
public:
    bool partition(string& s, int l, int r, int target) {
        if (l > r) 
            return target == 0;  // all digits used and target is 0, it's valid.
        
        int x = 0;
        for (int m = l ; m <= r; m++) {
            x = x * 10 + (s[m] - '0'); // stoi
            if (x > target) 
                break;  // Stop early
            if (partition(s, m + 1, r, target - x)) 
                return 1;
        }
        return 0;
    }

    int punishmentNumber(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            int x = i * i;
            string s = to_string(x);
            if (partition(s, 0, s.size() - 1, i)) 
                sum += x;
        }
        return sum;
    }
};
