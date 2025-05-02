class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        queue<int> Q;
        string vis = dominoes;
        vector<int> time(n, -1);
        for(int i=0; i<n; i++){
            if(dominoes[i] != '.'){
                Q.push(i);
                time[i] = 0;
            }
        }
        while(Q.size()){
            int ind = Q.front();
            Q.pop();

            if(vis[ind] == 'L'){
                if(ind-1 >= 0){
                    if(time[ind-1] == -1){
                        time[ind-1] = time[ind] + 1;
                        vis[ind-1] = vis[ind];
                        Q.push(ind-1);
                    }
                    else if(time[ind-1] > time[ind]){
                        vis[ind-1] = '.';
                    }
                }
            }
            else{
                if(ind+1 < n){
                    if(time[ind+1] == -1){
                        time[ind+1] = time[ind] + 1;
                        vis[ind+1] = vis[ind];
                        Q.push(ind+1);
                    }
                    else if(time[ind+1] > time[ind]){
                        vis[ind+1] = '.';
                    }
                }
            }
            
        }
        return vis;
    }
};