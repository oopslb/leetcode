/*
暴力枚举
*/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int len[n+10];
        long long int mask[n+10];
        memset(mask, 0, sizeof(mask));
        for(int i = 0; i < n; ++i){
            int length = words[i].size();
            for(int j = 0; j < length; ++j){
                mask[i] |= 1 << (words[i][j] - 'a');
            }
            len[i] = length;
        }
        int ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                int cnt = len[i] * len[j];
                if((mask[i] & mask[j])==0){
                    //cout<<i<<' '<<j<<' '<<cnt;
                    if(cnt > ans){
                        ans = cnt;
                    }
                }
            }
        }
        return ans;


    }
};
