class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int five = 0;
        int ten = 0;

        for(int bill : bills) {

            // customer gives 5
            if(bill == 5) {

                five++;
            }

            // customer gives 10
            else if(bill == 10) {

                if(five == 0)
                    return false;

                five--;
                ten++;
            }

            // customer gives 20
            else {

                // prefer 10 + 5
                if(ten >= 1 && five >= 1) {

                    ten--;
                    five--;
                }

                // otherwise 3 fives
                else if(five >= 3) {

                    five -= 3;
                }

                else {

                    return false;
                }
            }
        }

        return true;
    }
};
