/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
    int bfs(int src, unordered_set<int> &vis, unordered_map<int,Employee*> mp){
        int sum = mp[src]->importance;
        queue<int> Q;
        Q.push(src);
        vis.insert(src);
        while(Q.size()){
            int currNode = Q.front();
            Q.pop();
            for(auto adjNode : mp[currNode]->subordinates){
                if(vis.find(adjNode) == vis.end()){
                    vis.insert(adjNode);  
                    sum += mp[adjNode]->importance;
                    Q.push(adjNode);  
                }
            }
        }
        return sum;
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*> mp; //{id,addressOfEmployee}
        unordered_set<int> vis;
        for(auto e : employees){
            mp[e->id] = e;
        }
        return bfs(id, vis, mp);
    }
};