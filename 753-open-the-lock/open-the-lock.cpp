class Solution {
    void pushAllNextCombiToQueue( queue<pair<string,int>> &q, unordered_set<string> &vis, unordered_set<string> &deads, string currCombi, int turn){
        for(int i=0; i<4; i++){
            string next1, next2;
            next1 = next2 = currCombi;
            next1[i] = '0';
            next2[i] = '9';
            char digAtI = currCombi[i];
            if(digAtI + 1 != 58)    next1[i] = digAtI + 1;
            if(digAtI - 1 != 47)    next2[i] = digAtI - 1;
            if(vis.find(next1) == vis.end() && deads.find(next1) == deads.end()){
                vis.insert(next1);
                q.push({next1,turn+1});
            }
            if(vis.find(next2) == vis.end() && deads.find(next2) == deads.end()){
                vis.insert(next2);
                q.push({next2,turn+1});
            }
        }
    }
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> vis, deads;
        for(auto d : deadends)
            deads.insert(d);
        queue<pair<string,int>> q; //{combi,turn}
        if(deads.find("0000") == deads.end()){
            q.push({"0000",0});
            vis.insert("0000");
        }
        while(q.size()){
            string currCombi = q.front().first;
            int turn = q.front().second;
            if(currCombi==target)   return turn;
            q.pop();
            pushAllNextCombiToQueue(q, vis, deads, currCombi, turn);
        }
        return -1;
    }
};