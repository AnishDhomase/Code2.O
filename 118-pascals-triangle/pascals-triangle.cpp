class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        vector<int> prev;
        for(int r=1; r<=numRows; r++){
            vector<int> currRow;
            for(int c=0; c<r; c++){
                if(c==0 || c==r-1)
                    currRow.push_back(1);
                else
                    currRow.push_back(prev[c] + prev[c-1]);
            }
            pascal.push_back(currRow);
            prev = currRow;  
        }
        return pascal;
    }
};