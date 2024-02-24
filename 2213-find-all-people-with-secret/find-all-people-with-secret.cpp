class Solution {
    vector<int> dijkstras(vector<vector<pair<int,int>>> adjList){
        int n = adjList.size();
        vector<int> ans, time(n, 1e9);
        time[0] = 0;
        set<pair<int,int>> st;
        st.insert({0,0});
        while(st.size()){
            auto topNode = *st.begin();
            int currNode = topNode.second, currTime = topNode.first;
            st.erase(topNode);
            ans.push_back(currNode);
            for(auto adj : adjList[currNode]){
                int adjTime = adj.second;
                int adjnode = adj.first;
                if(currTime <= adjTime){
                    if(time[adjnode] == 1e9){
                        st.insert({adjTime,adjnode});
                        time[adjnode] = adjTime;
                    }
                    else if(adjTime < time[adjnode]){
                        st.erase({time[adjnode], adjnode});
                        st.insert({adjTime,adjnode});
                        time[adjnode] = adjTime;
                    }
                }
            }
        }
        return ans;
    }
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>> adjList(n, vector<pair<int,int>>(0));
        for(auto m : meetings){
            adjList[m[0]].push_back({m[1],m[2]});
            adjList[m[1]].push_back({m[0],m[2]});
        }
        adjList[0].push_back({firstPerson,0});
        adjList[firstPerson].push_back({0,0});
        return dijkstras(adjList);
        
    }
};