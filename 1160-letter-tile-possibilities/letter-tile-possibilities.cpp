class Solution {
public:
    int count = 0;

    void backtrack(string &tiles, vector<int> &freq) {
        // Increment count for each valid sequence (not including empty sequence)
        count++;

        // Try using each character that is still available
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                // Use this character and reduce its frequency
                freq[i]--;
                backtrack(tiles, freq);
                // Backtrack: restore the frequency of this character
                freq[i]++;
            }
        }
    }

    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0); // Frequency array for characters A-Z
        for (char tile : tiles) {
            freq[tile - 'A']++; // Count the occurrences of each letter
        }

        backtrack(tiles, freq);
        return count - 1; // Subtract 1 to exclude the empty sequence
    }
};
