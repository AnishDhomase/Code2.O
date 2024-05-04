class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boatsReq = 0;
        sort(people.begin(), people.end());
        int i=0, j=people.size()-1;
        while(i<=j){
            if(i==j){ i++; j--; }
            else if(people[i] + people[j] <= limit){ i++; j--; }
            else j--;
            boatsReq++;
        }
        return boatsReq;
    }
};