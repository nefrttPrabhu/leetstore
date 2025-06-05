class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    map<int, int> losses; 

    for (auto& match : matches) {
        int winner = match[0];
        int loser = match[1];
        
        if (losses.find(winner) == losses.end())
            losses[winner] = 0;  
        
        losses[loser]++;
    }

    vector<int> noLosses;
    vector<int> oneLoss;

    for (auto& [player, lossCount] : losses) {
        if (lossCount == 0)
            noLosses.push_back(player);
        else if (lossCount == 1)
            oneLoss.push_back(player);
    }

    return {noLosses, oneLoss};
    }
};