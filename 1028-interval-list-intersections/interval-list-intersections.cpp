class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> intersectionList;
        vector<int> intersection(2);
        for(auto e : firstList){
            for(auto el : secondList){
                if(el[0] <= e[1] && e[0] <= el[1]){
                    if(e[0] <= el[0]) 
                        intersection[0] = el[0];
                    else    intersection[0] = e[0];
                    if(e[1] <= el[1]) 
                        intersection[1] = e[1];
                    else    intersection[1] = el[1];
                    intersectionList.push_back(intersection);
                }
                if(e[1] < el[0])    break;
            }
        }
        return intersectionList;
    }
};