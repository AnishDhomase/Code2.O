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
    bool isPath(int u, int v){
        int pu = getPar(u), pv = getPar(v);
        return pu == pv;
    }
};
class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        DSU dsu(n);
        int m = queries.size(), edgeCnt = edgeList.size();
        vector<bool> ans(m);
        vector<vector<int>> modQueries; //{limit, u, v, ind}
        vector<vector<int>> modEdges; //{wt, u, v}
        int i = 0;
        for(auto q : queries){
            modQueries.push_back({q[2], q[0], q[1], i});
            i ++;
        }
        sort(modQueries.begin(), modQueries.end());
        i = 0;
        for(auto e : edgeList){
            modEdges.push_back({e[2], e[0], e[1]});
            i ++;
        }
        sort(modEdges.begin(), modEdges.end());
        i = 0;
        for(auto q : modQueries){
            int limit = q[0], u = q[1], v = q[2], queryInd = q[3];
            while(i < edgeCnt && modEdges[i][0] < limit){
                int u = modEdges[i][1], v = modEdges[i][2];
                dsu.unionBySize(u,v);
                i ++;
            }
            ans[queryInd] = dsu.isPath(u,v); 
        }
        return ans;
    }
};