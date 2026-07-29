class Solution {
public:
    int minBitFlips(int start, int goal) {
        int c=0;
        int n=start^goal;
        for(int i=0;i<31;i++){
            if(n&(1<<i)) c++;
        }
        return c;
    }
};