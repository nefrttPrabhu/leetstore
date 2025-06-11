class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = n-1;

        while(l < h){
            int mid = l + (h - l) / 2;

            bool isEven;
            if((h - mid) % 2 == 0){
                isEven = true;
            }
            else{
                isEven = false;
            }

            if(nums[mid] == nums[mid + 1]){
                if(isEven){
                    l = mid + 2;
                }

                else{ 
                    h = mid - 1;
                }
            }
            else{
                if(isEven){
                    h = mid;
                }
                else{
                    l = mid + 2;
                }
            }
        }
        return nums[h];
    }
};


// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         int low = 0;
//         int high = nums.size() - 1;

//         int n = nums.size();
        
//         if ( n == 1 ) return nums[0];

//         if ( nums[0] != nums[1] ) return nums[0];

//         if ( nums[n-2] != nums[n-1] ) return nums[n-1];

//         while(low <= high) {
//             int mid = (low + high) / 2;

//             if(nums[mid - 1] != nums[mid] && nums[mid + 1] != nums[mid]) {
//                 return nums[mid];
//             } 
// //take five numbers index will be from 0 - 4
//             else if(mid % 2 && nums[mid - 1] == nums[mid] ||    //if mid is odd means single element will be on the left of the mid 
//                     mid % 2 == 0 && nums[mid] == nums[mid + 1]) //if mid is even means remaining are even number of numbers to the right of mid so if mid and adjsecnt is equal means the single is on the right of mid + 1
//                     {
//                 low = mid + 1;
//             } 
            
//             else {
//                 high = mid - 1;
//             }
//         }
//         return 0;
//     }
// };