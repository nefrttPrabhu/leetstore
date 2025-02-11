// class Solution {
// public:

//     int maxPossibleBananas(vector<int>& piles) {
//         int maxi = 0;
//         for(int i: piles) {
//             maxi = max(i, maxi);
//         }
//         return maxi;
//     }

//     bool possible(vector<int>& piles, int mid, int h) {
//         for(int i = 0; i < piles.size(); i++) {
//             h -= piles[i] % mid ? (piles[i] / mid) + 1 : piles[i] / mid;
//         }
//         return h >= 0;
//     }


//     int minEatingSpeed(vector<int>& piles, int h) {
//         int low = 1;
//         int high = maxPossibleBananas(piles);

//         while(low <= high) {
//             int mid = (low + high) / 2;

//             if(possible(piles, mid, h)) {
//                 high = mid - 1;
//             } else {
//                 low = mid + 1;
//             }
//         }
//         return low;
//     }
// };

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int e = 0;
        int n = piles.size();
        for(int i=0;i<n;i++){
            if(piles[i]>e){
                e= piles[i];
            }
        }
        
        int s =1;
        int x = 0;
        while(s<=e){
            int mid = s+(e-s)/2;
            long long ans =0;
             for(int i=0;i<n;i++){
               ans += (piles[i] + mid - 1) / mid; 


             }
             if(ans>h){
                s=mid+1;
             }else{
                x= mid;
                e= mid-1;
             }
        }
        return x;
    }
};