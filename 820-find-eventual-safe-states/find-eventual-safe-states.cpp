class Solution {
    bool isCycle(int node, vector<vector<int>> &graph, vector<int> &vis){
        vis[node] = 2;
        for(auto adjNode : graph[node]){
            if(!vis[adjNode]){
                if(isCycle(adjNode, graph, vis))
                    return true;
            }
            else if(vis[adjNode] == 2)
                return true;
        }
        vis[node] = 1;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n = graph.size();
        vector<int> vis(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i])
                isCycle(i, graph, vis);
        }
        for(int i=0; i<n; i++){
            if(vis[i] == 1)
                ans.push_back(i);
        }
        return ans;
    }
};