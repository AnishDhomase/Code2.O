class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        int candiesCollected = 0;
        queue<int> Q;
        vector<int> vis(n, 0);
        for(auto initialBox: initialBoxes){
            vis[initialBox] = 1;
            if(status[initialBox] == 1){
                Q.push(initialBox);
                status[initialBox] = 2;
            }
        }
        while(Q.size() > 0){
            int box = Q.front();
            candiesCollected += candies[box];
            Q.pop();

            for(auto key: keys[box]){
                if(!vis[key]) {
                    status[key] = 1;
                    continue;
                }
                if(status[key] == 2) continue;
                Q.push(key);
                status[key] = 2;
            }

            for(auto containedBox: containedBoxes[box]){
                vis[containedBox] = 1;
                if(status[containedBox] == 1){
                    Q.push(containedBox);
                    status[containedBox] = 2;
                }
            }
            
        }
        return candiesCollected;
    }
};