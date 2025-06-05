class DSU {
    public:
    vector<int> par, size;
    DSU(int n){
        par.resize(n);
        size.resize(n, 1);
        for(int i=0; i<n; i++)
            par[i] = i;
    }
    int getPar(int u){
        if(par[u] == u) return u;
        return par[u] = getPar(par[u]);
    }
    void unionBySize(int u, int v){
        int parU = getPar(u);
        int parV = getPar(v);
        if(parU == parV) return;

        if(size[parU] > size[parV]){
            size[parU] += size[parV];
            par[parV] = parU;
        }
        else{
            size[parV] += size[parU];
            par[parU] = parV;
        }
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        string smallestEquiStr;
        DSU dsu(26);
        for(int i=0; i<s1.length(); i++)
            dsu.unionBySize(s1[i]-'a', s2[i]-'a');
        map<int, vector<int>> mp;
        vector<int> equival(26);
        for(int i=0; i<26; i++) {
            equival[i] = i;
            int ultimatePar = dsu.getPar(i);
            mp[ultimatePar].push_back(i);
        }
        
        for(auto &it: mp){
            auto v = it.second;
            if(v.size() == 1)   continue;

            sort(v.begin(), v.end());
            int lexSmallCharAscii = v[0];
            for(auto it: v)
                equival[it] = lexSmallCharAscii;
        }

        for(auto ch: baseStr){
            char chEqui = equival[ch-'a'] + 'a';
            smallestEquiStr += chEqui;
        }
        
        return smallestEquiStr;
    }
};