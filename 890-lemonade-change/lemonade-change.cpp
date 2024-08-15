class Solution {
    bool isChangeAvl(int bill, int &five, int &ten, int &twenty){
        if(bill == 5){
            five ++;
        }
        else if(bill == 10){
            ten ++;
            if(five == 0)   return false;
            five --;
        }
        else {
            twenty ++;
            if(ten && five){
                ten --;
                five --;
            }
            else if(five >= 3){
                five -= 3;
            }
            else   return false;
        }
        return true;
    }

public:
    bool lemonadeChange(vector<int>& bills) {
        int five, ten, twenty;
        five = ten = twenty = 0;
        for(auto bill: bills){
            if(!isChangeAvl(bill, five, ten, twenty))
                return false;
        }
        return true;
    }
};