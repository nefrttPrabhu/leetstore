class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        if(k == 1) return 'a';
        while(word.size() < k){
            int i = 0;
            int n = word.size();
            while(i < n){
                char ch = word[i] + 1;
                word += ch;
                if(word.size() == k){
                    cout << word;
                    return word[k-1];
                }
                i++;
            }
        }
        return word[k];
    }
};