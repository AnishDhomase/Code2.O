class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time=0, n=tickets.size();
        if(tickets[k] != 1){
            int minus = tickets[k]-1;
            for(int i=0; i<n; i++){
                if(tickets[i] >= minus){
                    tickets[i] -= minus;
                    time += minus;
                }
                else{
                    time += tickets[i];
                    tickets[i] = 0;
                }
            }
        }
        for(int i=0; i<=k; i++){
            if(tickets[i]){
                time++ ;
            }
        }
        return time;



        // int time = 0, n=tickets.size();
        // while(tickets[k]){
        //     for(int i=0; i<n; i++){
        //         if(tickets[i]){
        //             --tickets[i];
        //             time++;
        //         }
        //         if(tickets[k]==0)
        //             return time;
        //     }
        // }
        // return time;
    }
};