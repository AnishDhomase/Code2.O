class DSU{
    vector<int> size, par;
public:
    DSU(int n){
        size.resize(n, 1);
        for(int i=0; i<n; i++)
            par.push_back(i);
    }
    bool isGraphConnected(){
        int pars = 0, n = par.size();
        for(int i=1; i<n; i++){
            if(par[i]==i)
                pars++;
        }
        return pars == 1;
    }
    int parOf(int u){
        if(par[u] == u)
            return u;
        return par[u] = parOf(par[u]);
    }
    bool addEdge(int u, int v){
        int pu = parOf(u), pv = parOf(v);
        if(pu != pv){
            if(size[pu] >= size[pv]){
                size[pu] += size[pv];
                par[pv] = pu; 
            }
            else{
                size[pv] += size[pu];
                par[pu] = pv;
            }
            return 1;
        }
        return 0;

    }

};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int ct = 0;
        DSU base1(n+1), base2(n+1);
        for(auto e : edges){
            if(e[0] == 3){
                if(!base1.addEdge(e[1],e[2]))
                    ct++;
                base2.addEdge(e[1],e[2]);
            }      
        }
        for(auto e : edges){
            if(e[0] == 1){
                if(!base1.addEdge(e[1],e[2]))
                    ct++;
            }
            else if(e[0] == 2){
                if(!base2.addEdge(e[1],e[2]))
                    ct++;
            }      
        }
        if(!base1.isGraphConnected())
            return -1;
        if(!base2.isGraphConnected())
            return -1;
        return ct;
        
    }
};