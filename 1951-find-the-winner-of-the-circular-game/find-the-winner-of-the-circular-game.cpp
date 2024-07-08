class Solution {
    void eliminateNextPlayer(vector<int> &players, int &start, int k, int &playersRemaining){
        int n = players.size();
        for(int i=start, ct=0; ; i=(i+1)%n){
            if(players[i] != 0) ct ++;
            if(ct == k){
                players[i] = 0;
                for(int j=(i+1)%n;  ; j=(j+1)%n){
                    if(players[j] != 0){
                        start = j;
                        break; 
                    }
                }
                break;
            }
        }
        playersRemaining --;
    }
public:
    int findTheWinner(int n, int k) {
        vector<int> players;
        for(int i=1; i<=n; i++)
            players.push_back(i);

        int playersRemaining = n, start = 0;
        while(playersRemaining >= 2){
            eliminateNextPlayer(players, start, k, playersRemaining);
        }
        return players[start];
    }
};