class Solution {
public:
    void backtrack(string &tiles, unordered_set<string> &ans, string &current, vector<int> &freq) {
        if (!current.empty()) {
            ans.insert(current);  // Add the current permutation to the set if it's non-empty
        }

        for (int i = 0; i < tiles.size(); i++) {
            if (freq[i] > 0) {
                // Skip duplicates: if the character is the same as the previous one and the previous one hasn't been used, skip it.
                if (i > 0 && tiles[i] == tiles[i - 1] && freq[i - 1] > 0) continue;
                current.push_back(tiles[i]);
                freq[i]--;
                backtrack(tiles, ans, current, freq);  // Recur with the reduced frequency of the character
                current.pop_back();  // Backtrack
                freq[i]++;  // Restore frequency
            }
        }
    }

    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());  // Sort to make sure duplicates are adjacent
        unordered_set<string> ans;
        string current;
        vector<int> freq(tiles.size(), 1);  // Frequency map for each character
        backtrack(tiles, ans, current, freq);

        return ans.size();  // Return the count of unique permutations
    }
};
