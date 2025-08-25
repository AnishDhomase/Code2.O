class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        bool up = true;
        int r=0, c=0, rows=mat.size(), cols=mat[0].size();
        while(ans.size() != rows * cols){
            // Adjust r, c if not valid
            if(c == cols){
                up = !up;
                c --;
                r += 2;
            }
            else if(r == rows){
                up = !up;
                r --;
                c += 2;
            }
            else if(r == -1){
                up = !up;
                r = 0;
            }
            else if(c == -1){
                up = !up;
                c = 0;
            }

            // Add to ans
            ans.push_back(mat[r][c]);

            // move r, c acco to direction
            if(up){
                r --;
                c ++;
            }
            else{
                r ++;
                c --;
            }
        }
        return ans;
    }
};