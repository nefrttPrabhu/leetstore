/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x=0;
        for(int i = 0;i < nums.size(); i++){
            x=x^nums[i];
        }
        return x;
    }
};
*/


/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> h;

        for (int i = 0; i < nums.size(); i++) {
            h[nums[i]]++;
        }

        for (auto& pair : h) {
            if (pair.second == 1) {
                return pair.first;
            }
        }

        return -1; 
    }
};
*/

/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> h;
        
        // Single pass: Insert & Erase strategy
        for (int num : nums) {
            if (h.count(num)) {
                h.erase(num);  // If number is already in map, remove it
            } else {
                h[num] = 1;  // Otherwise, insert it
            }
        }

        // The remaining key in the map is the single number
        return h.begin()->first;
    }
};
*/


//striver
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());  

        for (int i = 0; i < nums.size() - 1; i += 2) {  
            if (nums[i] != nums[i + 1]) 
                return nums[i];
        }
        
        return nums.back(); 
    }
};



/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> unique;
        int sumSet = 0, sumArray = 0;

        for (int num : nums) {
            if (!unique.count(num)) {
                unique.insert(num);
                sumSet += num;
            }
            sumArray += num;
        }

        return 2 * sumSet - sumArray;
    }
};
*/



/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sumUnique = 0, sumArray = 0;
        sort(nums.begin(), nums.end());  // Sorting helps find unique sum

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i - 1])  
                sumUnique += nums[i];  // Add unique numbers
            sumArray += nums[i];  // Add all numbers
        }

        return 2 * sumUnique - sumArray;
    }
};
*/



/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // O(n log n) sorting

        for (int i = 0; i < nums.size() - 1; i += 2) {  
            if (nums[i] != nums[i + 1])  // Check adjacent elements
                return nums[i];
        }
        
        return nums.back();  // Last element is unique if no mismatch found
    }
};
*/