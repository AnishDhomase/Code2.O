class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_map<string,int> indegree;
        map<string,unordered_set<string>> adjList;
        queue<string> q;
        unordered_set<string> recipeSet(recipes.begin(), recipes.end());
        unordered_set<string> suppliesSet(supplies.begin(), supplies.end());
        vector<string> recipesPossible;

        for(int i=0; i<n; i++){
            string &recipeToMake = recipes[i];
            vector<string> &ingredientsRequired = ingredients[i];
            for(auto ingredient: ingredientsRequired){
                adjList[ingredient].insert(recipeToMake);
                indegree[recipeToMake] ++;
            }
        }
        for(auto suppl: supplies){
            if(indegree[suppl] == 0)
                q.push(suppl);
        }
        while(q.size() > 0){
            string item = q.front();
            q.pop();
            if(recipeSet.find(item) != recipeSet.end())
                recipesPossible.push_back(item);

            for(auto itemCanBeMadeFromThisItem: adjList[item]){
                indegree[itemCanBeMadeFromThisItem] --;
                if(indegree[itemCanBeMadeFromThisItem] == 0)
                    q.push(itemCanBeMadeFromThisItem);
            }

        }
        return recipesPossible;
    }
};