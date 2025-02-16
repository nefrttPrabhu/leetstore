class Solution {
public:
    vector<int> result;
    vector<bool> used;

    bool backtrack(vector<int>& seq, int index, int n) {
        if (index == seq.size()) 
            return true;
            
        if (seq[index] != 0) 
            return backtrack(seq, index + 1, n);

        for (int num = n; num >= 1; --num) {
            if (used[num]) 
                continue;

            if (num == 1) {
                seq[index] = 1;
                used[1] = true;

                if (backtrack(seq, index + 1, n)) 
                    return true;

                seq[index] = 0;
                used[1] = false;
            } 
            else {
                int secondIndex = index + num;
                if (secondIndex < seq.size() && seq[secondIndex] == 0) {
                    seq[index] = seq[secondIndex] = num;
                    used[num] = true;

                    if (backtrack(seq, index + 1, n)) 
                        return true;

                    seq[index] = seq[secondIndex] = 0;
                    used[num] = false;
                }
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        int size = 2 * (n - 1) + 1;
        vector<int> seq(size, 0);
        used.resize(n + 1, false);
        
        backtrack(seq, 0, n);
        return seq;
    }
};
