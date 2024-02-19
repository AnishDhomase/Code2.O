class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        long long msz = meetings.size(), i, t;
        vector<long long> freq(n,0);
        sort(meetings.begin(), meetings.end());
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> freeTimeHp;
        priority_queue<long long, vector<long long>, greater<long long>> avlRoomsHp;
        for(long long i=0; i<n; i++){
            avlRoomsHp.push(i);
        }
        for(i=0, t=0; i<msz; ){
            t = max(t, (long long)meetings[i][0]);
            while(freeTimeHp.size() && freeTimeHp.top().first <= t){
                long long room = freeTimeHp.top().second;
                freeTimeHp.pop();
                avlRoomsHp.push(room);
            }
            if(avlRoomsHp.size()){
                long long currMeetTime = meetings[i][1] - meetings[i][0];
                long long avlRoom = avlRoomsHp.top(); 
                avlRoomsHp.pop(); 
                freeTimeHp.push({t + currMeetTime, avlRoom});
                freq[avlRoom]++;
                i++;
            }
            else{
                t = max(t, freeTimeHp.top().first);
            }
        }
        long long max = 0, maxRoom = -1; 
        for(long long i=0; i<n; i++){
            if(max < freq[i]){
                max = freq[i];
                maxRoom = i;
            }
        }
        return maxRoom;






        // Brute Force : MLE
        // long long totalMeetsDone = 0;
        // long long msz = meetings.size();
        // queue<long long> delayedQ; //{timesOfMeets}
        // set<int> availableRooms;
        // unordered_map<int,int> meets; //{startTime, MeetTime}
        // unordered_map<long long,set<int>> emptyTime; //{EmptyTime, rooms}
        // vector<long long> freq(n,0); //{meetsDone @ith index}
        // for(auto meet : meetings){
        //     meets[meet[0]] = meet[1]-meet[0];
        // }
        // for(int i=0; i<n; i++){
        //     emptyTime[0].insert(i);
        // }
        // for(long long t=0; totalMeetsDone < msz; t++){
        //     while(emptyTime[t].size()){
        //         int it = *(emptyTime[t].begin());
        //         availableRooms.insert(it);
        //         emptyTime[t].erase(it);
        //     } //releasing Engaged Rooms
        //     while(availableRooms.size() && delayedQ.size()){
        //         int avlRoom = *(availableRooms.begin());
        //         long long delMeetTime = delayedQ.front();
        //         availableRooms.erase(avlRoom);
        //         delayedQ.pop();
        //         emptyTime[t + delMeetTime].insert(avlRoom);
        //         freq[avlRoom]++;
        //         totalMeetsDone++;
        //     } //scheduling Delayed Meets
        //     if(meets[t]){
        //         if(availableRooms.size()){
        //             int avlRoom = *(availableRooms.begin());
        //             long long MeetTime = meets[t];
        //             availableRooms.erase(avlRoom);
        //             meets.erase(t);
        //             emptyTime[t + MeetTime].insert(avlRoom);
        //             freq[avlRoom]++;
        //             totalMeetsDone++;
        //         }
        //         else{
        //             delayedQ.push(meets[t]);
        //         }
        //     }//Tackle meet starting @ t
        // }
        // int maxFreq = 0, mostBooked=-1;
        // for(int i=0; i<n; i++){
        //     if(maxFreq < freq[i]){
        //         maxFreq = freq[i];
        //         mostBooked = i;
        //     }
        // }
        // return mostBooked;
    }
};