class Solution {
    bool isBiBFS(int start, vector<vector<int>> &graph, vector<int> &color){
        queue<int> Q;
        Q.push(start);
        color[start] = 1;
        while(Q.size() > 0){
            int currNode = Q.front();
            Q.pop();
            for(auto adjNode : graph[currNode]){
                if(!color[adjNode]){
                    color[adjNode] = color[currNode] == 1 ? 2 : 1;
                    Q.push(adjNode);
                }
                else if(color[adjNode] == color[currNode])
                    return false;
            }
        }
        return true;
    }
    bool isBiDFS(int node, int clr, vector<vector<int>> &graph, vector<int> &color){
        color[node] = clr;
        for(auto adjNode : graph[node]){
            if(!color[adjNode]){
                int oppoClr = color[node] == 1 ? 2 : 1;
                if(!isBiDFS(adjNode, oppoClr, graph, color))
                    return false; 
            }
            else if(color[adjNode] == color[node])
                return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);

        for(int i=0; i<n; i++){
            if(!color[i]){
                if(! isBiDFS(i, 1, graph, color))
                    return false;
            }
        }
        return true;
    }
};