class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        bool sign = true;
        if(dividend>=0 && divisor<0) sign = false;
        if(dividend<0 && divisor>=0) sign = false;
        long long n=llabs((long long)dividend),d=llabs((long long)divisor);
        long long ans=0;
        while(n>=d){
            int c=0;
            while(n>=(d<<(c+1))){
                c++;
            }
            ans+=(1LL<<c);
            n-=(d<<c);
        }
        if(ans>=(1LL<<31) && sign==true) return INT_MAX;
        if(ans>=(1LL<<31) && sign==false) return INT_MIN;
        return sign?ans:(-ans);
    }
};