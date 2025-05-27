class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int candiesCollected = 0, n = status.size();
        queue<int> Q;
        vector<int> vis(n, 0);
        
        for(auto box: initialBoxes){
            vis[box] = 1;
            if(status[box] == 1){
                Q.push(box);
                status[box] = 2;
            }
        }
        while(Q.size() > 0){
            int currBox = Q.front();
            candiesCollected += candies[currBox];
            Q.pop();

            for(auto key: keys[currBox]){
                if(status[key] == 2)    continue;
                status[key] = 1;
                if(vis[key] == 1){
                    Q.push(key); 
                    status[key] = 2;
                }   
            } 
            for(auto containedBox: containedBoxes[currBox]){
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