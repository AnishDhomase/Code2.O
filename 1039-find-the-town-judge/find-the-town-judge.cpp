class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int judgeCt = 0, judge = -1;
        vector<pair<int,int>> degree(n+1,{0,0}); //{in,out}
        for(auto tr : trust){
            degree[tr[0]].second++;
            degree[tr[1]].first++;
        }
        for(int i=1; i<=n; i++){
            int indegree = degree[i].first;
            int outdegree = degree[i].second;
            if(indegree == n-1 && outdegree==0){
                judgeCt ++;
                judge = i;
            }  
        }
        if(judgeCt != 1) return -1;
        return judge;
    }
};