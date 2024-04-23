class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        unordered_map<int,unordered_set<int>> adjList;
        unordered_set<int> nodes;
        if(n==1)   return {0};
        for(auto e : edges){
            adjList[e[0]].insert(e[1]);
            adjList[e[1]].insert(e[0]);
            nodes.insert(e[0]);
            nodes.insert(e[1]);
        }
        vector<int> toDel;
        unordered_set<int> nextPossibleDel;
        for(auto it : adjList){
            if(it.second.size() == 1)
                toDel.push_back(it.first);
        }
        while(nodes.size() > 2){
            for(auto node : toDel){
                int adjnode = *(adjList[node].begin());
                adjList[adjnode].erase(node);
                adjList.erase(node);
                nodes.erase(node);
                nextPossibleDel.insert(adjnode);
            }
            toDel.clear();
            for(auto node : nextPossibleDel){
                if(adjList[node].size() == 1)
                    toDel.push_back(node);
            }
        }
        for(auto node : nodes)
            ans.push_back(node);
        return ans;

    }
};