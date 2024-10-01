class DSU{
    public:
    vector<int> par, size;
    DSU(int n){
        size.resize(n,1);
        for(int i=0; i<n; i++){
            par.push_back(i);
        }
    }
    int getPar(int node){
        if(par[node] == node)
            return node;
        return par[node] = getPar(par[node]);
    }
    void unionBySize(int u, int v){
        int pu = getPar(u), pv = getPar(v);
        if(pu == pv)    return;
        if(size[pu] >= size[pv]){
            size[pu] += size[pv];
            par[pv] = pu;
        }
        else{
            size[pv] += size[pu];
            par[pu] = pv;
        }
    }
};
class Solution {
    bool isValid(int r, int c, int n){
        return r >=0 && c >= 0 && r < n && c < n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), maxIsland = 1;
        DSU dsu(n*n);
        vector<int> dR = {0,-1,0,1}, dC = {-1,0,1,0};
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                if(grid[r][c] == 1){
                    int nodeNum = r * n + c;
                    for(int i=0; i<2; i++){
                        int adjR = r + dR[i];
                        int adjC = c + dC[i];
                        if(isValid(adjR,adjC,n) && grid[adjR][adjC] == 1){
                            int adjNodeNum = adjR * n + adjC; 
                            int parNode = dsu.getPar(nodeNum);
                            int parAdjNode = dsu.getPar(adjNodeNum);
                            if(parNode != parAdjNode){
                                maxIsland = max(maxIsland, dsu.size[parNode] + dsu.size[parAdjNode]);
                                dsu.unionBySize(nodeNum,adjNodeNum);
                            }
                        }
                    }
                }
            }
        }
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                if(grid[r][c] == 0){
                    unordered_set<int> adjPars;
                    for(int i=0; i<4; i++){
                        int adjR = r + dR[i];
                        int adjC = c + dC[i];
                        if(isValid(adjR,adjC,n) && grid[adjR][adjC] == 1){
                            int adjNodeNum = adjR * n + adjC; 
                            int parAdjNode = dsu.getPar(adjNodeNum);
                            adjPars.insert(parAdjNode);
                        }
                    }
                    int islandSz = 1;
                    for(auto adjPar : adjPars){
                        islandSz += dsu.size[adjPar];
                    }
                    maxIsland = max(maxIsland, islandSz);
                }
            }
        }
        return maxIsland;
    }
};