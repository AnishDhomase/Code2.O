class Solution {
    int bfs(vector<int> res, vector<vector<int>> adjList, int n){
        int ct=1;
        vector<int> vis(n,0);
        for(auto r : res)    vis[r]++;
        vis[0]++;
        queue<int> Q;
        Q.push(0);
        while(Q.size()){
            int currNode = Q.front();
            Q.pop();
            for(auto adjNode : adjList[currNode]){
                if(!vis[adjNode]){
                    ct++;
                    vis[adjNode]++;
                    Q.push(adjNode);

                }
            }
        }
        return ct;
    }
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adjList(n,vector<int>(0));
        for(auto e : edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        return bfs(restricted, adjList, n);
    }
};