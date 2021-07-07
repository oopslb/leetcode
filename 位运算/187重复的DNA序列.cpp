/*
用2位表示一种字符，20位就可以无冲突地表示一个长度为10的串
*/

class Solution {
public:
    int judge(char c){
        if(c=='A')return 0;
        if(c=='C')return 1;
        if(c=='G')return 2;
        return 3;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        bitset< 1 << 20 >vis, use;
        int hash = 0;
        int mod = (1 << 20) - 1;
        for(int i = 0; i < 10; ++i){
            hash = (hash << 2) | (judge(s[i]));
        }
        vis.set(hash);
        for(int i = 10; i < s.size(); ++i){
             hash = ((hash << 2) & mod) | (judge(s[i]));
             if(use[hash])continue;
             if(vis[hash]){
                ans.push_back(s.substr(i - 9, 10));
                use.set(hash);
             }
             else vis.set(hash);
        }
        return ans;
    }
};

