class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        unordered_map<int,int> clrCount, clrOfBall;
        vector<int> ans;
        for(auto q: queries){
            int i = q[0], color = q[1];
            if(clrOfBall[i] != 0){      
                int prevColor = clrOfBall[i];
                clrCount[prevColor] --;
                if(clrCount[prevColor] == 0)
                    clrCount.erase(prevColor);
            }
            clrOfBall[i] = color;
            clrCount[color] ++;
            ans.push_back(clrCount.size());
        }
        return ans;



    }
};