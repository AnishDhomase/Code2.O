class DSU{
    public:
    vector<int> par, size, vertices;

    DSU(int n){
        par.resize(n);
        vertices.resize(n, 1);
        size.resize(n, 0);
        for(int i=0; i<n; i++)
            par[i] = i;
    }

    int getParent(int u){
        if(par[u] == u) return u;
        return par[u] = getParent(par[u]);
    }

    void unionBySize(int u, int v){
        int pu = getParent(u), pv = getParent(v);
        if(pu == pv){
            size[pu] ++;
        }
        else{
            if(size[pu] > size[pv]){
                size[pu] += size[pv] + 1;
                vertices[pu] += vertices[pv];
                par[pv] = pu;
            }
            else{
                size[pv] += size[pu] + 1;
                vertices[pv] += vertices[pu];
                par[pu] = pv;
            }
        }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int cnt = 0;
        DSU dsu(n);
        for(auto edge: edges)
            dsu.unionBySize(edge[0], edge[1]);
        for(int i=0; i<n; i++){
            int parOfI = dsu.getParent(i);
            if(parOfI == i){
                int verticesInComponent = dsu.vertices[i];
                int requiredEdgesForCompleteComponent = verticesInComponent * (verticesInComponent-1) / 2;
                int actualEdgesInComponent = dsu.size[i];
                if(actualEdgesInComponent == requiredEdgesForCompleteComponent)
                    cnt ++;
            }
        }
        return cnt;
    }
};