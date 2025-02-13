        // sort(s.begin(),s.end());              //ascending sort array and string 
        // sort(s.rbegin(),s.rend());            //descending sort for string only
        // sort(s.begin(),s.end(),greater<int>); //descending sort for array only

class Solution {
public:
    string frequencySort(string s) {
        string result;
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> pq;

        for (char ch : s) {
            mp[ch]++;
        }

        for (auto [ch, freq] : mp) {
            pq.push({freq, ch});
        }
        
        while (!pq.empty()) {
            auto [freq, ch] = pq.top();
            pq.pop();
            result.append(freq, ch); 
        }

        return result;
    }
};
