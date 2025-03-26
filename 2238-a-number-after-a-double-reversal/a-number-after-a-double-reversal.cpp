class Solution {
public:
    bool isSameAfterReversals(int num) {
        if(num == 0){
            return true;
        }

        if(!(num % 10)){
            return false;
        }

        return true;
    }
};