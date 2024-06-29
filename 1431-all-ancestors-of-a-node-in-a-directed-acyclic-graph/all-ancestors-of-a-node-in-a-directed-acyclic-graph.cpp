class Solution {
    void dfs(int child, int par, vector<int> &isVis, vector<vector<int>> &adjList, vector<set<int>> &ansSet){
        if(isVis[child]){
            if(par == -1)   return;
            for(auto nodes : ansSet[child])
                ansSet[par].insert(nodes);
            ansSet[par].insert(child);
            return;
        }
        for(auto adjNode : adjList[child]){
            dfs(adjNode, child, isVis, adjList, ansSet);
            for(auto nodes : ansSet[adjNode])
                ansSet[child].insert(nodes);
            ansSet[child].insert(adjNode);
        }
        isVis[child] = 1;
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n), adjList(n);
        vector<set<int>> ansSet(n);
        vector<int> inDegree(n,0), isVis(n,0);
        for(auto edge : edges){
            int from = edge[0], to = edge[1];
            inDegree[from] ++;
            adjList[to].push_back(from);
        }
        for(int i=0; i<n; i++)
            if(inDegree[i] == 0)    
                dfs(i, -1, isVis, adjList, ansSet);
        for(int i=0; i<n; i++){
            for(auto parnodeOfIthNode : ansSet[i])
                ans[i].push_back(parnodeOfIthNode);
        }
        return ans;     
    }
};