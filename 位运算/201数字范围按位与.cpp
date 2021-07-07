/*
找相同前缀，后面只要改变肯定会出现0，这样一定取0
*/

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int m = (1 << 30);
        int ans = 0;
        while(m > 0 && (left&m) == (right&m)){
            ans |= left&m;
            m >>= 1;
        }
        return ans;
    }
};


