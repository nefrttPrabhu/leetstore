class Solution {
public:
int findLucky(vector<int>& arr) {
    unordered_map<int, int> freq;

    for (int num : arr) {
        freq[num]++;
    }

    int result = -1;

    for (auto& it : freq) {
        if (it.first == it.second) {
            result = max(result, it.first);
        }
    }

    return result;
}
};