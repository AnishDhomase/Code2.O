class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
        int rows = image.size(), cols = image[0].size();
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        int startColor = image[sr][sc];
        vis[sr][sc] = 1;
        image[sr][sc] = color;
        queue<pair<int,int>> Q;
        Q.push({sr,sc});
        vector<int> dX = {0, 0, 1, -1};
        vector<int> dY = {1, -1, 0, 0};
        while(Q.size()){
            auto currPixel = Q.front();
            int y = currPixel.first, x = currPixel.second;
            Q.pop();
            for(int i=0; i<4; i++){
                int adjX = x + dX[i];
                int adjY = y + dY[i];
                if(0 <= adjX && adjX < cols && 0 <= adjY && adjY < rows){
                    if(!vis[adjY][adjX] && image[adjY][adjX] == startColor){
                        vis[adjY][adjX] = 1;
                        image[adjY][adjX] = color;
                        Q.push({adjY,adjX});
                    }
                }
            }
        }
        return image;
    }
};