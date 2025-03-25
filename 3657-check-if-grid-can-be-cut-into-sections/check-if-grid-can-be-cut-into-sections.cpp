bool assumingOnlyXDirection(vector<int> &i1, vector<int> &i2){
    if(i1[0] < i2[0])   return true;
    if(i1[0] > i2[0])   return false;
    return i1[2] < i2[2];
}
bool assumingOnlyYDirection(vector<int> &i1, vector<int> &i2){
    if(i1[1] < i2[1])   return true;
    if(i1[1] > i2[1])   return false;
    return i1[3] < i2[3];
}
class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int m = rectangles.size();
        sort(rectangles.begin(), rectangles.end(), assumingOnlyXDirection);
        int prevStartX = rectangles[0][0], prevEndX = rectangles[0][2];
        int cut = 0;
        for(int i=1; i<m; i++){
            vector<int> nextRectangle = rectangles[i];
            int nextStartX = nextRectangle[0], nextEndX = nextRectangle[2];
            if(nextStartX < prevEndX)
                prevEndX = max(prevEndX, nextEndX);
            else{
                cut ++;
                if(cut == 2)    return true;
                prevStartX = nextStartX;
                prevEndX = nextEndX;
            }
        }

        sort(rectangles.begin(), rectangles.end(), assumingOnlyYDirection);
        int prevStartY = rectangles[0][1], prevEndY = rectangles[0][3];
        cut = 0;
        for(int i=1; i<m; i++){
            vector<int> nextRectangle = rectangles[i];
            int nextStartY = nextRectangle[1], nextEndY = nextRectangle[3];
            if(nextStartY < prevEndY)
                prevEndY = max(prevEndY, nextEndY);
            else{
                cut ++;
                if(cut == 2)    return true;
                prevStartY = nextStartY;
                prevEndY = nextEndY;
            }
        }
        return false;
    }
};