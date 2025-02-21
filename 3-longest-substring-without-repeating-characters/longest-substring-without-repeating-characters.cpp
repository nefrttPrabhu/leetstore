class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int cnt = 0;
        unordered_map<char, int> mp;

        for(right = 0; right < s.size(); right++) {

            while(mp.find(s[right]) != mp.end()) {
                mp[s[left]]--;
                if(mp[s[left]] == 0) mp.erase(s[left]);
                left++;
            } 

            mp[s[right]]++;

            cnt = max(cnt, right - left + 1);
        }
        return cnt;
    }
};