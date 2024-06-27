class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        if(edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
            return edges[0][0];
        return edges[0][1];
        // unordered_map<int,int> mp;
        // int n = edges.size() + 1;
        // for(auto e : edges){
        //     int v1 = e[0], v2 = e[1];
        //     mp[v1]++;
        //     mp[v2]++;
        // }
        // for(auto it : mp){
        //     int v = it.first, freq = it.second;
        //     if(freq == n-1)
        //         return v;
        // }
        return -1;
    }
};