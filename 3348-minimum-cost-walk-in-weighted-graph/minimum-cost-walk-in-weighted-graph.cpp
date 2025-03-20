class DSU{
    vector<int> par, size;
    public:
    DSU(int n){
        size.resize(n, 1);
        par.resize(n);
        for(int i=0; i<n; i++)
            par[i] = i;
    }
    int getPar(int n){
        if(par[n] == n) return n;
        return par[n] = getPar(par[n]);
    }
    bool unionBySize(int u, int v){
        int pu = getPar(u), pv = getPar(v);
        if(pu == pv)    return false;
        if(size[pu] > size[pv]){
            size[pu] += size[pv];
            par[pv] = pu;
        }
        else{
            size[pv] += size[pu];
            par[pu] = pv;
        }
        return true;
    }
};
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> ans;
        DSU dsu(n);

        for(auto edge: edges)
            dsu.unionBySize(edge[0], edge[1]);
        
        unordered_map<int,int> mp;
        for(auto edge: edges){
            int u = edge[0], v = edge[1];
            int wt = edge[2];
            int parent = dsu.getPar(u);
            if(mp.find(parent) == mp.end()) mp[parent] = wt;
            else                            mp[parent] &= wt;
        }
        for(auto q: query){
            int u = q[0], v = q[1];
            int pu = dsu.getPar(u), pv = dsu.getPar(v);
            if(pu != pv)    ans.push_back(-1);
            else            ans.push_back(mp[pu]);
        }
        return ans;

    }
};