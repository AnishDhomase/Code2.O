class DSU {
    vector<int> par, size;
public:
    DSU(int n){
        size.resize(n,1);
        par.resize(n);
        for(int i=0; i<n; i++)
            par[i]=i;
    }
    int parOf(int v){
        if(par[v]==v)
            return v;
        return par[v] = parOf(par[v]);
    }
    void unionBySize(int u, int v){
        int parU = parOf(u), parV = parOf(v);
        int sizeU = size[parU], sizeV = size[parV];
        if(parU != parV){
            if(sizeU > sizeV){
                size[parU] += size[parV];
                par[parV] = parU;
            }
            else{
                size[parV] += size[parU];
                par[parU] = parV;
            }
        }
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DSU dsu(n);
        for(auto e : edges)
            dsu.unionBySize(e[0],e[1]);
        return dsu.parOf(source) == dsu.parOf(destination);
    }
};