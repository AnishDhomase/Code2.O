class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans = 0;
        unordered_map<int,int> freq; //{skill,freqOfSkill}
        int n = skill.size();
        int totalTeams = n/2;
        int totalSkillSum = 0;
        for(auto s : skill){
            freq[s]++;
            totalSkillSum += s;
        }
        if(totalSkillSum % totalTeams)
            return -1;
        int teamSum = totalSkillSum / totalTeams;
        for(int i=0; i<n; i++){
            int elem = skill[i], teamate;
            if(freq[elem]){
                freq[elem]--;
                teamate = teamSum - elem;
                if(freq[teamate]){
                    freq[teamate]--;
                    ans += elem * teamate;
                }
                else return -1;
            }
        }
        return ans;


    }
};