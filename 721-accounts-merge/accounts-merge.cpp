struct DSU{
    vector<int> par, size;
    DSU(int n){
        par.resize(n);
        for(int i=0; i<n; i++)
            par[i] = i;
        size.resize(n, 1);
    }
    int parentOf(int u){
        if(par[u] == u)
            return u;
        return par[u] = parentOf(par[u]);
    }
    void unionOf(int u, int v){
        int pu = parentOf(u);
        int pv = parentOf(v);
        if(pu != pv){
            if(size[pu] >= size[pv]){
                size[pu] += size[pv];
                par[pv] = pu;
            }
            else{
                size[pv] += size[pu];
                par[pu] = pv;
            }
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<vector<string>> ans;
        DSU dsu(n);
        unordered_map<string, int> mp; //mail -> accInd + 1
        unordered_map<int, vector<string>> ansMp; // accInd -> {mails}
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(!mp[mail]){
                    mp[mail] = i+1;
                }
                else{
                    dsu.unionOf(mp[mail]-1, i);
                }
            }
        }
        for(auto rec : mp){
            int acc = rec.second - 1;
            string mail = rec.first;
            int parOfAcc = dsu.parentOf(acc);
            ansMp[parOfAcc].push_back(mail);
        }
        for(auto rec : ansMp){
            int acc = rec.first;
            vector<string> mails = rec.second;
            sort(mails.begin(), mails.end());
            vector<string> subAns;
            subAns.push_back(accounts[acc][0]);
            for(auto mail : mails)
                subAns.push_back(mail);
            ans.push_back(subAns);
        }
        return ans;
    }
};