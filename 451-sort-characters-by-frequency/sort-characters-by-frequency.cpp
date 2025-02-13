        // sort(s.begin(),s.end());              //ascending sort array and string 
        // sort(s.rbegin(),s.rend());            //descending sort for string only
        // sort(s.begin(),s.end(),greater<int>); //descending sort for array only

// class Solution {
// public:
//     string frequencySort(string s) {
//         string result;
//         unordered_map<char, int> mp;
//         priority_queue<pair<int, char>> pq;

//         for (char ch : s) {
//             mp[ch]++;
//         }

//         for (auto [ch, freq] : mp) {
//             pq.push({freq, ch});
//         }
        
//         while (!pq.empty()) {
//             auto [freq, ch] = pq.top();
//             pq.pop();
//             result.append(freq, ch); 
//         }

//         return result;
//     }
// };


typedef pair<char, int> p;
struct lambda{
    bool operator()(p &p1, p &p2){
        return p1.second < p2.second; //max heap
    }
};

class Solution {
public:
    string frequencySort(string s) {
        priority_queue<p, vector<p>, lambda> pq;
        unordered_map<char, int> mp;

        for(char &ch : s){
            mp[ch]++;
        }

        for(auto it : mp){
            pq.push({it.first, it.second});
        }

        string res = "";

        while(!pq.empty()){
            p temp = pq.top();
            pq.pop();
            res += string(temp.second, temp.first);
        }
        return res;
    }
};