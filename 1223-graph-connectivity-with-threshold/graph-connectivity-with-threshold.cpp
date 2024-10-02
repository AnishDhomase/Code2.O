class DSU {
    vector<int> par, size;
    public:
    DSU(int n){
        size.resize(n, 0);
        for(int i=0; i<n; i++)
            par.push_back(i);
    }
    int getPar(int node){
        if(par[node] == node)
            return node;
        return par[node] = getPar(par[node]);
    }
    void unionBysize(int u, int v){
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
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        DSU dsu(n+1);
        vector<bool> ans;
        for(int i=threshold + 1; i<=n; i++){
            for(int j=2; i*j<=n; j++){
                dsu.unionBysize(i, i*j);
            }
        }
        for(auto q : queries){
            ans.push_back(dsu.isPath(q[0], q[1]));
        }
        return ans;
    }
};