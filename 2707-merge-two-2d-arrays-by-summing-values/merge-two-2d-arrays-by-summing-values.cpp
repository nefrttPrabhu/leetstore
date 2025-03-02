// class Solution {
// public:
//     vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
//         vector<vector<int>> result;
//         int i = 0, j = 0;
        
//         while (i < nums1.size() && j < nums2.size()) {
//             if (nums1[i][0] == nums2[j][0]) {
//                 result.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
//                 i++; j++;
//             } else if (nums1[i][0] < nums2[j][0]) {
//                 result.push_back(nums1[i]);
//                 i++;
//             } else {
//                 result.push_back(nums2[j]);
//                 j++;
//             }
//         }
        
//         while (i < nums1.size()) {
//             result.push_back(nums1[i]);
//             i++;
//         }
        
//         while (j < nums2.size()) {
//             result.push_back(nums2[j]);
//             j++;
//         }
        
//         return result;
//     }
// };




class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& n1, vector<vector<int>>& n2) {
        vector<vector<int>>v;
        int i =0 ; int j = 0;

        while (i < n1.size() || j < n2.size()) {
            if (i < n1.size() && j < n2.size() && n1[i][0] == n2[j][0]) {
                v.push_back({n1[i][0], (n1[i][1] + n2[j][1])});
                i++;
                j++;
            } else if (j == n2.size() || i < n1.size() && n1[i][0] < n2[j][0]) {
                v.push_back(n1[i]);
                i++;
            } else {
                v.push_back(n2[j]);
                j++;
            }
        }
        return v;
    }
};