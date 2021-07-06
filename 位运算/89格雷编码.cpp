/*
规律题
00 01 11 10
000 001 011 010 110 111 101 100
从n=2到n＝3，前面四位保持不变。后面四位只是在第三位上多了一个1，然后位数的变化情况和前四位刚好相反对称！

*/
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans = {0};
        if(n==0)return ans;
        ans = {0,1};
        for(int i=1;i<n;i++){
            int len = ans.size();
            for(int j=0;j<len;j++){
                ans.push_back(ans[len-j-1]+(1<<i));
            }
        }
        return ans;
    }
};
