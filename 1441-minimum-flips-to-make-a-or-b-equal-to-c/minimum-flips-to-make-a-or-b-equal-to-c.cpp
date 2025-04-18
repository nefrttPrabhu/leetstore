class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        while(a != 0 || b != 0 || c != 0) {
            if((c & 1) == 1){
                if(((a & 1) == 0) && ((b & 1) == 0)){
                    cnt++;
                }
            }

            if((c & 1) == 0){
                if((a & 1) == 1){
                    cnt++;
                }

                if((b & 1) == 1){
                    cnt++;
                }
            }
            a = a >> 1;
            b = b >> 1;
            c = c >> 1;
        }
        return cnt;
    }
};



/* 1liner solution '0'
int minFlips(int a, int b, int c) {
    return popcount<uint>((a | b) ^ c) + popcount<uint>(a & b & ((a | b) ^ c));
}
*/