/*
通过divisor的不断叠加，直到累加和超过dividend，我们记录累加次数。
比如 结果是5， 其二进制为101， 就可以变成1+4
*/
class Solution {
public:
    int divide(int dividend, int divisor) {

        int ans = 0;
        long long a = (long long)abs((long long)dividend), b = (long long)abs((long long)divisor);;
        int f = -1;
         if(dividend>0&&divisor>0)
            f = 1;
        if(dividend<0&&divisor<0)
            f = 1;
        if(b==1){
            if(a<=2147483647||f==-1)
                return a*f;
            else return 2147483647;
        }
        while(a>=b){
            long long  cnt = 1,base=b;
            while(a >= (base<<1)){
                cnt <<= 1;
                base <<= 1;
            }
            ans += cnt;
            a -= base;
        }
        ans *= f;
        return ans;
    }
};
