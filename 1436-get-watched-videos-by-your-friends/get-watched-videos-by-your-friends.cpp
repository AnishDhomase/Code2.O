class Solution {
    vector<int> bfs(int src, int lvl, vector<vector<int>> adjList){
        int n = adjList.size();
        vector<int> lvlNodes, vis(n,0);
        queue<pair<int,int>> Q; //{node,level}
        vis[src]++;
        Q.push({src,0});
        while(Q.size()){
            auto curr = Q.front();
            int currNode = curr.first, currNodelvl = curr.second;
            Q.pop();
            if(currNodelvl == lvl){
                lvlNodes.push_back(currNode);
                continue;
            }
            for(auto adjNode : adjList[currNode]){
                if(!vis[adjNode]){
                    vis[adjNode]++;
                    Q.push({adjNode,currNodelvl+1});
                }
            }
        }
        return lvlNodes;
    }
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vector<string> ans;
        vector<int> lvlNodes = bfs(id, level, friends);
        unordered_map<string,int> freq;
        map<int,vector<string>> mp;
        for(auto node : lvlNodes){
            for(auto video : watchedVideos[node]){
                freq[video]++;
            }
        }
        for(auto it : freq)
            mp[it.second].push_back(it.first);
        for(auto it : mp){
            vector<string> subAns = it.second;
            sort(subAns.begin(), subAns.end());
            for(auto str : subAns)
                ans.push_back(str);
        }
        return ans;
        
    }
};