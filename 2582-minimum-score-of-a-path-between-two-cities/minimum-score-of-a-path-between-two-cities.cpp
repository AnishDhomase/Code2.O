class DSU{
    vector<int> par, size, minEdge;
public:
    int minbtn(int a=1e9, int b=1e9, int c=1e9){
        if(a<b){
            if(a<c)
                return a;
            return c;
        }
        else{
            if(b<c)
                return b;
            return c;
        }
        return 1e9;
    }
    DSU(int sz){
        size.resize(sz, 1);
        minEdge.resize(sz, 1e9);
        par.resize(sz);
        for(int i=1; i<sz; i++)
            par[i] = i;
    }
    int parOf(int u){
        if(par[u] == u)
            return u;
        return par[u] = parOf(par[u]);
    }
    void addEdge(int u, int v, int w){
        int pu = parOf(u), pv = parOf(v);
        if(pu != pv){
            if(size[pu] >= size[pv]){
                size[pu] += size[pv];
                par[pv] = pu;
                minEdge[pu] = minbtn(w, minEdge[pu], minEdge[pv]);
            }
            else{
                size[pv] += size[pu];
                par[pu] = pv;
                minEdge[pv] = minbtn(w, minEdge[pu], minEdge[pv]);
            }
        }
        else{
                minEdge[pv] = minbtn(w, minEdge[pv]);
        }

    }
    int minEdgeOf(int u){
        return minEdge[u];
    }
};
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DSU dsu(n+1);
        for(auto r : roads){
            dsu.addEdge(r[0],r[1],r[2]);
        }
        return dsu.minEdgeOf(dsu.parOf(1));
    }
};