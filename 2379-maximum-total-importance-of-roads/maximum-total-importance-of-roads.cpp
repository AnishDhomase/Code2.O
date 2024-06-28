class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long max = 0;
        vector<int> degree(n,0);
        vector<int> value(n,0);
        map<int,vector<int>> mp;
        for(auto r : roads){
            int v1 = r[0], v2 = r[1];
            degree[v1]++;
            degree[v2]++;
        }
        for(int i=0; i<n; i++){
            mp[degree[i]].push_back(i); 
        }
        int v = 1;
        for(auto pr : mp){
            for(auto e : pr.second){
                value[e] = v;
                v++;
            }
        }
        for(auto r : roads){
            int v1 = r[0], v2 = r[1];
            max += value[v1] + value[v2];
        }
        return max;
    }
};