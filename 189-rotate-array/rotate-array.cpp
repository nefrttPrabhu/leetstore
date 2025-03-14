class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};


/*
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int len = nums.size();
        vector<int> newNums;
        for (int i=0; i< len; i++) {
            newNums.push_back(nums[(i+len - (k%len))%len]);
        }
        nums = newNums;
    }
};
*/


/*
class Solution {
public:
void rotate(vector<int>& nums,int k,int n)
{
    vector<int> temp;
    k=k%n;
    for(int i=n-k;i<n;i++)
    {
        temp.push_back(nums[i]);
    }
    for(int i=n-1;i>=k;i--)
    {
        nums[i]=nums[i-k];
    }
    for(int i=0;i<k;i++)
    {
        nums[i]=temp[i];
    }
}
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        rotate(nums,k,n);
    }
};
*/