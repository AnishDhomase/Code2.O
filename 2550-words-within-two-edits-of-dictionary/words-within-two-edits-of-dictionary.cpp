class Solution {
    bool canEqlAfterMin2Edits(string &q, string &d){
        int misMatchCnt = 0;
        for(int i=0; i<q.length() && misMatchCnt < 3; i++){
            if(q[i] != d[i])
                misMatchCnt ++;
        }
        return misMatchCnt <= 2;
    }
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(auto q: queries){
            for(auto d: dictionary){
                if(canEqlAfterMin2Edits(q,d)){
                    ans.push_back(q);
                    break;
                }
            }
        }
        return ans;
    }
};