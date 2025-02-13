class Solution {
public:
    string frequencySort(string s) {
        // sort(s.begin(),s.end());              //ascending sort array and string 
        // sort(s.rbegin(),s.rend());            //descending sort for string only
        // sort(s.begin(),s.end(),greater<int>); //descending sort for array only

        unordered_map<char, int> charCount;
        for (char c : s) {
            charCount[c]++;
        }

        vector<char> sortedChars;
        for (const auto& entry : charCount) {
            sortedChars.push_back(entry.first);
        }
        sort(sortedChars.begin(), sortedChars.end(), [&](char a, char b) {
            return charCount[a] > charCount[b];
        });

        string result;
        for (char c : sortedChars) {
            result += string(charCount[c], c);
        }

        return result;
    }
};