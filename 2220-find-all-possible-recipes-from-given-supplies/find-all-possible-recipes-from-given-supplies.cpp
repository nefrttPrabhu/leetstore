
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> inDegree;
        unordered_map<string, vector<string>> graph;
        unordered_set<string> available(supplies.begin(), supplies.end());
        queue<string> q;

        for (int i = 0; i < recipes.size(); i++) {
            inDegree[recipes[i]] = ingredients[i].size();
            for (const string& ing : ingredients[i]) {
                graph[ing].push_back(recipes[i]);
            }
        }

        for (const string& s : supplies) {
            q.push(s);
        }

        vector<string> result;

        while (!q.empty()) {
            string item = q.front();
            q.pop();

            if (inDegree.find(item) != inDegree.end()) {
                result.push_back(item);
            }

            for (const string& recipe : graph[item]) {
                if (--inDegree[recipe] == 0) {
                    q.push(recipe);
                }
            }
        }

        return result;
    }
};
